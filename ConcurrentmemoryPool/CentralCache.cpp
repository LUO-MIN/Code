#include "Common.h"
#include "CentralCache.h"
#include "PageCache.h"


CentralCache CentralCache::_inst;

//从page cache获取一个span
Span* CentralCache::GetOneSpan(SpanList& spanlist, size_t byte_size)
{
	Span* span = spanlist.Begin();
	while (span != spanlist.End())
	{
		if (span->_list != nullptr)
		{
			return span;
		}
		else{
			span = span->_next;
		}
	}
	//span为空 去Page Cache中去拿
	Span* newspan = PageCache::GetInstance()->NewSpan(SizeClass::NumMovePage(byte_size));
	//将span页切分成需要的对象并链接起来
	char* cur = (char*)(newspan->_pageid << PAGE_SHIFT);
	char* end = cur + (newspan->_npage << PAGE_SHIFT);
	newspan->_list = cur;
	newspan->_objsize = byte_size;
	
	while (cur + byte_size < end)
	{
		char* next = cur + byte_size;
		NEXT_OBJ(cur) = next;
		cur = next;
	}
	NEXT_OBJ(cur) = nullptr;

	spanlist.PushFront(newspan);
	return newspan;
}

size_t CentralCache::FetchRangeObj(void*& start, void *& end, size_t n, size_t byte_size)
{
	
	size_t index = SizeClass::Index(byte_size);
	SpanList& spanlist = _spanlist[index];

	// 加锁
	//spanlist.Lock();
	std::unique_lock<std::mutex> lock(spanlist._mtx);
	Span* span = GetOneSpan(spanlist, byte_size);//找到一个非空的span

	//从span中获取一定数量的对象
	size_t batchsize = 0;
	void* prev = nullptr;
	void* cur = span->_list;
	for (size_t i = 0; i < n; ++i)
	{
		prev = cur;
		cur = NEXT_OBJ(cur);  
		++batchsize;
		if (cur == nullptr)//考虑内存不足20的情况
			break;
	}

	start = span->_list;
	end = prev;

	span->_list = cur;
	span->_usecount += batchsize;

	//将空的span移到最后，保持非空span在最前面
	if (span->_list == nullptr)
	{
		spanlist.Erase(span);
		spanlist.PushBack(span);
	}
	//spanlist.Unlock();
	return batchsize;
}

void CentralCache::ReleaseListToSpans(void* start, size_t size)
{
	size_t index = SizeClass::Index(size);
	SpanList& spanlist = _spanlist[index];
	std::unique_lock<std::mutex> lock(spanlist._mtx);

	while (start)
	{
		void* next = NEXT_OBJ(start);
		// 加锁
		//spanlist.Lock();
		//std::unique_lock<std::mutex> lock(spanlist._mtx);

		Span* span = PageCache::GetInstance()->MapObjectToSpan(start);
		NEXT_OBJ(start) = span->_list;
		span->_list = start;
		// 当一个span的对象全部释放回来，将span还给pagecache，并且做页合并
		if (--span->_usecount == 0)
		{
			spanlist.Erase(span);
			PageCache::GetInstance()->ReleaseSpanToPageCahce(span);
		}

		//spanlist.Unlock();

		start = next;
	}
}
