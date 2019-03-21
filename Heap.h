#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>


typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;


void HeapInit(Heap* pHeap);
void HeapCreate(Heap* pHeap, HPDataType* a, int n);

void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
void HeapDestory(Heap* hp);

void HeapSort(HPDataType* a, int n);

void TestHeap();


