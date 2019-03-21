#include "Heap.h"

void Swap(HPDataType* pd1, HPDataType* pd2)
{
	HPDataType d=*pd1;
	*pd1 = *pd2;
	*pd2 = d;
}

//下调函数
void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选左孩子中最大的
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			++child;
		}

		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

		

	}
}

//上调函数
void AdjustUp(int *a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}

	}
}

void HeapInit(Heap* pHeap)
{
	assert(pHeap);
	pHeap->_array = NULL;
	pHeap->_size = pHeap->_capacity = 0;
}

void HeapCreate(Heap* pHeap, HPDataType* a, int n)
{
	assert(pHeap);
	pHeap->_array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(pHeap->_array, a, sizeof(HPDataType)*n);
	pHeap->_size = pHeap->_capacity = n;

	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(pHeap->_array, pHeap->_size, i);
	}


}
void HeapPush(Heap* pHeap, HPDataType x)
{
	assert(pHeap);
	if (pHeap->_size == pHeap->_capacity)
	{
		size_t newcapacity = pHeap->_capacity = 0 ? 3 : pHeap->_capacity * 2;
		pHeap->_array = realloc(pHeap->_array, sizeof(HPDataType)*newcapacity);
		pHeap->_array[pHeap->_size++] = x;
	}

	pHeap->_array[pHeap->_size++] = x;
	AdjustUp(pHeap->_array, pHeap->_size, pHeap->_size - 1);
}

void HeapPop(Heap* pHeap)
{
	Swap(&pHeap->_array[0], &pHeap->_array[pHeap->_size - 1]); 
	pHeap->_size--;

	AdjustDown(pHeap->_array, pHeap->_size, 0);
}
HPDataType HeapTop(Heap* pHeap)
{
	assert(pHeap);

	return pHeap->_array[0];
}
int HeapSize(Heap* pHeap)
{
	return pHeap->_size;
}
int HeapEmpty(Heap* pHeap)
{
	return pHeap->_size == 0 ? 0 : 1;
}
void HeapDestory(Heap* pHeap)
{
	free(pHeap->_array);
	pHeap->_array = NULL;
	pHeap->_size =pHeap->_capacity = 0;
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void HeapPrint(Heap* pHeap)
{
	for (int i = 0; i < pHeap->_size; ++i)
	{
		printf("%d ", pHeap->_array[i]);
	}
	printf("\n");
}

void TestHeap()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	Heap hp;
	HeapInit(&hp);
	HeapCreate(&hp, a, sizeof(a) / sizeof(HPDataType));
	HeapPush(&hp,70);

	HeapPrint(&hp);
}
