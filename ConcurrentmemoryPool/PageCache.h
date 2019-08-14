#pragma once

#include "Common.h"

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_inst;
	}
	Span* AllocBigPageObj(size_t size);
	void FreeBigPageObj(void* ptr, Span* span);

	Span* _NewSpan(size_t n);
	Span* NewSpan(size_t n);

	// 获取从对象到span的映射
	Span* MapObjectToSpan(void* obj);

	// 释放空闲span回到Pagecache，并合并相邻的span
	void ReleaseSpanToPageCahce(Span* span);
private:
	SpanList _spanlist[NPAGES];
	std::unordered_map<PageID, Span*> _idspanmap;

	std::mutex _mtx;
private:
	PageCache()
	{}
	PageCache(const PageCache&) = delete;

	static PageCache _inst;
};

