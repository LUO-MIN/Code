#pragma once
#include "Common.h"
#include "ThreadCache.h"
#include "PageCache.h"


static inline void* ConcurrentAlloc(size_t size)
{
	if (size > MAX_BYTES)
	{
		return malloc(size);
	}
	else{
		if (tlslist == nullptr)
		{
			//cout << std::this_thread::get_id() << endl;
			tlslist = new ThreadCache;
			//cout << tlslist << endl;
		}

		return tlslist->Allocate(size);
	}
}

static inline void ConcurrentFree(void* ptr)
{
	Span* span = PageCache::GetInstance()->MapObjectToSpan(ptr);
	size_t size = span->_objsize;
	if (size > MAX_BYTES)
	{
		PageCache::GetInstance()->FreeBigPageObj(ptr, span);
	}
	else
	{
		tlslist->Deallocate(ptr, size);
	}
}