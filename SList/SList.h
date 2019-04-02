#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;//存放数据
	struct SListNode* _next;//存下数据的一个指针
}SListNode;

typedef struct SList
{
	SListNode* _head;//一个指向第一个节点的的指针
	SListNode* _tail;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);

void SListPushBack(SList* plist, SLTDataType x);
void SListPopBack(SList* plist);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);

SListNode* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 删除pos后面位置的值
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);

void TestSList();
