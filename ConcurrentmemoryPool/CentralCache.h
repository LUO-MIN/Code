#pragma once
#include "Common.h"

//��Ƴɵ���ģʽ����֤ȫ��Ψһ
class CentralCache
{
public:
	static CentralCache* GetInstance()
	{
		return &_inst;
	}

	//��page cache��ȡһ��span
	Span* GetOneSpan(SpanList& spanlist, size_t byte_size);


	//�����Ļ����ȡһ�������Ķ����thread Cache
	size_t FetchRangeObj(void*& start, void *& end, size_t n, size_t byte_size);

	// ��һ�������Ķ����ͷŵ�span���
	void ReleaseListToSpans(void* start, size_t size);
private:
	SpanList _spanlist[NLISTS];

private:
	CentralCache()
	{}
	CentralCache(CentralCache&) = delete;

	static CentralCache _inst; 
};
