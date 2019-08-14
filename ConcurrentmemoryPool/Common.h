#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <assert.h>

#include <thread>
#include <mutex>

using std::cout;
using std::endl;

#include <windows.h>
const size_t MAX_BYTES = 64 * 1024;//central Cache能够申请的最大内存，大于这个值们就要向PageCache要
const size_t NLISTS = 184;
const size_t NPAGES = 128;
const size_t PAGE_SHIFT = 12;


inline static void*& NEXT_OBJ(void* obj)
{
	return *((void**)obj);
}

class FreeList  //用来管理内存块对象
{
public:
	void Push(void* obj)
	{
		NEXT_OBJ(obj) = _list;
		_list = obj;
		++_size;
	}

	void PushRange(void* start, void* end, size_t n)
	{
		NEXT_OBJ(end) = _list;
		_list = start;

	}

	void* Pop()
	{
		void* obj = _list;
		_list = NEXT_OBJ(obj);
		--_size;
		return obj;
	}
	bool Empty()
	{
		return _list == nullptr;
	}
	size_t Size()
	{
		return _size;
	}

	size_t MaxSize()
	{
		return _maxsize;
	}

	void SetMaxSize(size_t maxsize)
	{
		_maxsize = maxsize;
	}

	void* PopRange()
	{
		_size = 0;
		void* list = _list;
		_list = nullptr;

		return list;
	}

private:
	void* _list=nullptr;  //类型是什么都可以
	size_t _size = 0;
	size_t _maxsize = 1;
};

class SizeClass   //计算大小，确定位置
{
public:
	inline static size_t _Index(size_t size, size_t align) //库里的实现
	{
		//如果范围是9-16 +7 》16-23
		size_t alignnum = 1 << align;
		return ((size + alignnum - 1) >> align) - 1;
	}

	inline static size_t _Roundup(size_t size, size_t align)
	{
		size_t alignnum = 1 << align;
		return (size + alignnum - 1) & ~(alignnum - 1);
	}
	// 控制在12%左右的内碎片浪费
	// [1,128]				8byte对齐 freelist[0,16)
	// [129,1024]			16byte对齐 freelist[16,72)
	// [1025,8*1024]		128byte对齐 freelist[72,128)
	// [8*1024+1,64*1024]	1024byte对齐 freelist[128,184)
	inline static size_t Index(size_t size)
	{
		assert(size <= MAX_BYTES);

		// 每个区间有多少个链
		static int group_array[4] = { 16, 56, 56, 56 };
		if (size <= 128)
		{
			return _Index(size, 3);
		}
		else if (size <= 1024)
		{
			return _Index(size - 128, 4) + group_array[0];
		}
		else if (size <= 8192)
		{
			return _Index(size - 1024, 7) + group_array[0] + group_array[1];
		}
		else//if (size <= 65536)
		{
			return _Index(size - 8 * 1024, 10) + group_array[0] + group_array[1] + group_array[2];
		}
	}


	// 对齐大小计算
	static inline size_t Roundup(size_t bytes)
	{
		assert(bytes <= MAX_BYTES);

		if (bytes <= 128){
			return _Roundup(bytes, 3);
		}
		else if (bytes <= 1024){
			return _Roundup(bytes, 4);
		}
		else if (bytes <= 8192){
			return _Roundup(bytes, 7);
		}
		else {//if (bytes <= 65536){
			return _Roundup(bytes, 10);
		}
	}

	static size_t NumMoveSize(size_t size)
	{
		if (size == 0)
			return 0;

		int num = (int)(MAX_BYTES / size);
		if (num < 2)
			num = 2;

		if (num > 512)
			num = 512;

		return num;
	}

	// 计算一次向系统获取几个页
	static size_t NumMovePage(size_t size)
	{
		size_t num = NumMoveSize(size);
		size_t npage = num*size;
		npage >>= PAGE_SHIFT;
		if (npage == 0)
			npage = 1;
		return npage;
	}

};

#ifdef _WIN32
typedef size_t PageID;
#else
typedef long long PageID;
#endif // _WIN32

struct Span
{
	PageID _pageid = 0; // 页号
	size_t _npage = 0;  // 页数


	Span* _prev = nullptr;
	Span* _next = nullptr;

	void* _list = nullptr;	 // 链接对象的自由链表
	size_t _objsize = 0;	 // 对象的大小

	size_t _usecount = 0;	 // 对象使用计数
};

//带头双向带头循环span链表
class SpanList
{
public:
	SpanList()
	{
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}

	Span* Begin()
	{
		return _head->_next;
	}

	Span* End()
	{
		return _head;
	}

	SpanList(const SpanList&) = delete;
	SpanList& operator=(const SpanList&) = delete;

	~SpanList()
	{
		Span* cur = _head->_next;
		while (cur != _head)
		{
			Span* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}

	void PushBack(Span* newspan)//最后一个的前一个插入
	{
		Insert(End(), newspan);
	}

	void PushFront(Span* newspan)//头插
	{
		Insert(Begin(), newspan);
	}

	Span* PopBack()
	{
		Span* span = _head->_prev;
		Erase(span);

		return span;
	}

	Span* PopFront()//头插
	{
		Span* span = _head->_next;
		Erase(span);

		return span;
	}
	
	bool Empty()
	{
		return _head->_next == _head;
	}

	//在pos的位置上插入一个newspan
	void Insert(Span* cur, Span* newspan)
	{
		Span* prev = cur->_prev;
		//prev newspan cur

		prev->_next = newspan;
		newspan->_next = cur;
		
		newspan->_prev = prev;
		cur->_prev = newspan;
	}
	void Erase(Span* cur)
	{
		Span* prev = cur->_prev;
		Span* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;
	}
	void Lock()
	{
		_mtx.lock();
	}

	void Unlock()
	{
		_mtx.unlock();
	}

	Span* _head;
	std::mutex _mtx;
};