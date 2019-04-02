//#pragma once 

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

//静态顺序表
//#define N 10
//typedef int SLDataType;  //给结构体重命名
//struct SeqList
//{
//	SLDataType _a[N];  // 数组
//	size_t _size;      // 有效数据的个数
//};

//void SeqListInit(SeqList* psl);//初始化链表
//void SqeqListDestory(SeqList* psl); //销毁链表
//
//
//void SeqListPushBack(SeqList* psl, SLDataType x);//尾插
//void SeqListPopBack(SeqList* psl);
//void PushFront(SeqList* psl, SLDataType x);
//void PopFornt(SeqList* psl);
//
//void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//任意位置插入
//void SeqListErase(SeqList* psl, size_t pos);//删除指定一个位置
//void SeqListRemove(SeqList* psl, size_t pos, SLDataType x);//删除一个指定值
//

//动态顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _a;
	size_t _size;      //有多少个有效数据
	size_t _capacity;  //容量
}SeqList;

void CheckCapacity(SeqList* psl);
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListInit(SeqList* psl, size_t capacity);//初始化链表
void SqeqListDestory(SeqList* psl); //销毁链表


void SeqListPushBack(SeqList* psl, SLDataType x);//尾插
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFornt(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//任意位置插入
void SeqListErase(SeqList* psl, size_t pos);//删除指定一个位置
void SeqListRemove(SeqList* psl, SLDataType x);//删除一个指定值
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);

void SeqListPrint(SeqList* psl);
void TestSeqList();

void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x);
void SeqListRemoveAll(SeqList* psl, SLDataType x);





#endif // __SEQLIST_H__