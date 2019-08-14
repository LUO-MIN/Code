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
const size_t MAX_BYTES = 64 * 1024;//central Cache�ܹ����������ڴ棬�������ֵ�Ǿ�Ҫ��PageCacheҪ
const size_t NLISTS = 184;
const size_t NPAGES = 128;
const size_t PAGE_SHIFT = 12;


inline static void*& NEXT_OBJ(void* obj)
{
	return *((void**)obj);
}

class FreeList  //���������ڴ�����
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
	void* _list=nullptr;  //������ʲô������
	size_t _size = 0;
	size_t _maxsize = 1;
};

class SizeClass   //�����С��ȷ��λ��
{
public:
	inline static size_t _Index(size_t size, size_t align) //�����ʵ��
	{
		//�����Χ��9-16 +7 ��16-23
		size_t alignnum = 1 << align;
		return ((size + alignnum - 1) >> align) - 1;
	}

	inline static size_t _Roundup(size_t size, size_t align)
	{
		size_t alignnum = 1 << align;
		return (size + alignnum - 1) & ~(alignnum - 1);
	}
	// ������12%���ҵ�����Ƭ�˷�
	// [1,128]				8byte���� freelist[0,16)
	// [129,1024]			16byte���� freelist[16,72)
	// [1025,8*1024]		128byte���� freelist[72,128)
	// [8*1024+1,64*1024]	1024byte���� freelist[128,184)
	inline static size_t Index(size_t size)
	{
		assert(size <= MAX_BYTES);

		// ÿ�������ж��ٸ���
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


	// �����С����
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

	// ����һ����ϵͳ��ȡ����ҳ
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
	PageID _pageid = 0; // ҳ��
	size_t _npage = 0;  // ҳ��


	Span* _prev = nullptr;
	Span* _next = nullptr;

	void* _list = nullptr;	 // ���Ӷ������������
	size_t _objsize = 0;	 // ����Ĵ�С

	size_t _usecount = 0;	 // ����ʹ�ü���
};

//��ͷ˫���ͷѭ��span����
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

	void PushBack(Span* newspan)//���һ����ǰһ������
	{
		Insert(End(), newspan);
	}

	void PushFront(Span* newspan)//ͷ��
	{
		Insert(Begin(), newspan);
	}

	Span* PopBack()
	{
		Span* span = _head->_prev;
		Erase(span);

		return span;
	}

	Span* PopFront()//ͷ��
	{
		Span* span = _head->_next;
		Erase(span);

		return span;
	}
	
	bool Empty()
	{
		return _head->_next == _head;
	}

	//��pos��λ���ϲ���һ��newspan
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