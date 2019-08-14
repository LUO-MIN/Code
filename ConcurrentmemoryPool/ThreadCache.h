#pragma once

#include "Common.h"

class ThreadCache
{
public:
	//������ͷ��ڴ����
	void* Allocate(size_t size);
	void Deallocate(void* ptr,size_t size);

	//��Central Cache��ȡ����
	void* FetchFromCentralCache(size_t index, size_t size);

	//�ͷŶ���ʱ���������ʱ�������ڴ浽���Ķ�
	void ListTooLong(FreeList* list, size_t size);
private:
	FreeList _freeList[NLISTS];//��������   ��һ����������
};

//TLS
_declspec (thread) static ThreadCache* tlslist = nullptr;