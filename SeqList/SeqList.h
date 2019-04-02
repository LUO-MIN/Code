//#pragma once 

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

//��̬˳���
//#define N 10
//typedef int SLDataType;  //���ṹ��������
//struct SeqList
//{
//	SLDataType _a[N];  // ����
//	size_t _size;      // ��Ч���ݵĸ���
//};

//void SeqListInit(SeqList* psl);//��ʼ������
//void SqeqListDestory(SeqList* psl); //��������
//
//
//void SeqListPushBack(SeqList* psl, SLDataType x);//β��
//void SeqListPopBack(SeqList* psl);
//void PushFront(SeqList* psl, SLDataType x);
//void PopFornt(SeqList* psl);
//
//void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//����λ�ò���
//void SeqListErase(SeqList* psl, size_t pos);//ɾ��ָ��һ��λ��
//void SeqListRemove(SeqList* psl, size_t pos, SLDataType x);//ɾ��һ��ָ��ֵ
//

//��̬˳���
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _a;
	size_t _size;      //�ж��ٸ���Ч����
	size_t _capacity;  //����
}SeqList;

void CheckCapacity(SeqList* psl);
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListInit(SeqList* psl, size_t capacity);//��ʼ������
void SqeqListDestory(SeqList* psl); //��������


void SeqListPushBack(SeqList* psl, SLDataType x);//β��
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFornt(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);//����λ�ò���
void SeqListErase(SeqList* psl, size_t pos);//ɾ��ָ��һ��λ��
void SeqListRemove(SeqList* psl, SLDataType x);//ɾ��һ��ָ��ֵ
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);

void SeqListPrint(SeqList* psl);
void TestSeqList();

void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x);
void SeqListRemoveAll(SeqList* psl, SLDataType x);





#endif // __SEQLIST_H__