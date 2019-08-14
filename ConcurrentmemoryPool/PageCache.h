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

	// ��ȡ�Ӷ���span��ӳ��
	Span* MapObjectToSpan(void* obj);

	// �ͷſ���span�ص�Pagecache�����ϲ����ڵ�span
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

