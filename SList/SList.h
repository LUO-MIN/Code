#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;//�������
	struct SListNode* _next;//�������ݵ�һ��ָ��
}SListNode;

typedef struct SList
{
	SListNode* _head;//һ��ָ���һ���ڵ�ĵ�ָ��
	SListNode* _tail;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);

void SListPushBack(SList* plist, SLTDataType x);
void SListPopBack(SList* plist);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);

SListNode* SListFind(SList* plist, SLTDataType x);
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ɾ��pos����λ�õ�ֵ
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);

void TestSList();
