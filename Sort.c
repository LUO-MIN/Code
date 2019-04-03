#include "Sort.h"


void Swap(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


void InsertSort(int* a, int n)
{
	assert(a);

	int i = 0;
	
	for (i = 0; i < n-1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end]>tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
}

//1 预排序     2 插入排序
void ShellSort(int* a, int n)
{
	assert(a);

	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end]>tmp)
			{
				a[end + gap] = a[end];
				end = end - gap;
			}

			a[end + gap] = tmp;
		}
	}

}

void AdjustDown(int* a, int n, int* root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child]>a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}


	}
}
//void HeapSort(int* a, int n)
//{
//	int i = 0;
//	for (i = (n - 2) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, j);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, n, j);
//		--end;
//	}
//}
//
//
//
//选一个数，放到合适的位置。选两个数，最大和最小的下标的数
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		Swap(&a[begin], &a[min]);
		if (begin == max)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		++begin;
		--end;

	}
};



	void BubbleSort(int* a, int n)
	{
		assert(a);

		int i = 0;
		int end = n;
		while (end > 0)
		{
			int flag = 0;
			for (i = 1; i < n; i++)
			{
				if (a[i - 1]>a[i])
				{
					Swap(&a[i - 1], a[i]);
					flag = 1;
				}
			}

			if (flag == 0)
			{
				break;
			}

			--end;
		}
	};

	//int partSort1(int* a, int begin,int end)//单趟的排序
	//{
	//	int key = a[begin];
	//	int start = begin;
	//	while (begin<end)
	//	{
	//		//end找小
	//		while (begin<end && a[end] >= key)
	//		{
	//			--end;
	//		}
	//		//begin 找大
	//		while (begin < end && a[begin] <= key)
	//		{
	//			++begin;
	//		}
	//
	//		Swap(&a[begin], &a[end]);
	//	}
	//
	//	Swap(&a[begin], a[start]);
	//	return begin;
	//}
	//
	////三数取中
	//int PartSort2(int* a, int begin, int end)
	//{
	//	//begin是空缺
	//	int key = begin;
	//	while (begin < end)
	//	{
	//		while (begin < end && a[end] >= key)
	//		{
	//			--end;
	//		}
	//		//end变成新的空缺
	//		a[begin] = a[end];
	//
	//		while (begin < end && a[begin] <= key)
	//		{
	//			++begin;
	//		}
	//		a[end] = a[begin];
	//	}
	//
	//	a[begin] = key;
	//
	//	return begin;
	//}
	//
	////前后指针法
	//int PartSort3(int* a, int begin, int end)
	//{
	//	int key = a[begin];
	//	int prev = begin;
	//	int cur = begin + 1;
	//	while (cur <= end)
	//	{
	//		if (a[cur] < key && ++prev != cur)
	//		{
	//			Swap(&a[cur], &a[prev]);
	//		}
	//		++cur;
	//	}
	//	Swap(&a[begin], &a[prev]);
	//
	//	return prev;
	//}
	//
	//void QuickSort(int* a, int left, int right)
	//{
	//	if (left >= right)
	//	{
	//		return;
	//	}
	//
	//	if (right - left < 10)
	//	{
	//		InsertSort1(a + left, right - left + 1);
	//	}
	//	else
	//	{
	//		int div = PartSort(a, left, right);
	//
	//		QuickSort(a, left, div - 1);
	//		QuickSort(a, div + 1, right);
	//	}
	//}
	//
	////快排非递归
	//void QuickSortR(int* a, int left, int right)
	//{
	//	Stack st;
	//	StackInit(&st, 10);
	//	if (left < right)
	//	{
	//		StackPush(&st, right);
	//		StackPush(&st, left);
	//	}
	//
	//	while (StackEmpty(&st) != 0)
	//	{
	//		left = StackTop(&st);
	//		StackPop(&st);
	//		right = StackTop(&st);
	//		StackPop(&st);
	//
	//		int div = PartSort(a, left, right);
	//		//left  div-1
	//		if (left < div - 1)
	//		{
	//			StackPush(&st,div-1);
	//			StackPush(&st, left);
	//		}
	//		//div+1 right
	//		if (div + 1 < right)
	//		{
	//			StackPush(&st, right);
	//			StackPush(&st, div + 1);
	//		}
	//
	//	}
	//}
	//
	//void _MegreSort(int* a, int left, int right, int* tmp)
	//{
	//	if (left >= right)
	//	{
	//		return;
	//	}
	//	int mid = left + (right - left) >> 1;
	//	//left mid
	//	_MegreSort(a, left, mid, tmp);
	//	//mid+1 right
	//	_MegreSort(a, mid + 1, right, tmp);
	//
	//	int begin1 = left, end1 = mid;
	//	int begin2 = mid + 1, end2 = right;
	//	int index = 0;
	//	while (begin1 <= end1 && begin1 <= end2)
	//	{
	//		if (a[begin1] < a[begin2])
	//		{
	//			tmp[index++] = a[begin1++];
	//		}
	//		else
	//		{
	//			tmp[index++] = a[begin++];
	//		}
	//		while (begin1 <= end1)
	//		{
	//			tmp[index++] = a[begin++];
	//		}
	//		while (begin2 <= end2)
	//		{
	//			tmp[index++] = a[begin2++];
	//		}
	//
	//		memcpy(a + left, tmp+left, sizeof(int)*(right - left + 1));
	//	}
	//}
	////归并排序
	//void MegreSort(int* a, int n)
	//{
	//	assert(a);
	//	int* tmp = (int*)malloc(sizeof(int)*n);
	//	_MegreSort(a, 0, n - 1, tmp);
	//	free(tmp);
	//}
	//
	//void CountSort(int* a, int n)
	//{
	//	int max = a[0],min = a[0];
	//	for (int i = 0; i < n; ++i)
	//	{
	//		if (a[min]>max)
	//		{
	//			max = a[i];
	//		}
	//		if (a[i] < min)
	//		{
	//			min = a[i];
	//		}
	//
	//		int range = max - min + 1;
	//		int* countArray = (int*)malloc(range*sizeof(int));
	//		memset(countArray, 0, sizeof(int)*range);
	//
	//		for (int i = 0; i < n; ++i)
	//		{
	//			countArray[a[i] - min]++;
	//		}
	//
	//		int index = 0;
	//		for (int i = 0; i < range; ++i)
	//		{
	//	//		while (countArray[i]--)
	//			{
	//				a[index++] = i + min;
	//			}
	//		}
	//	}
	//}

	void TestSort();
	{

		int a[] = { 8, 45, 3, 24, 31, 45, 56, 67, 78, 89, 1, 4, 7, 9 };
		//InsertSort(a, sizeof(a) / sizeof(a[0]));
		//ShellSort(a, sizeof(a) / sizeof(a[0]));
		//SelectSort(a, sizeof(a) / sizeof(a[0]));
		BubbleSort(a, sizeof(a) / sizeof(a[0]));
		/*QuickSort(a,0, sizeof(a) / sizeof(a[0]));
		QuickSortR(a,0, sizeof(a) / sizeof(a[0]));
		MegreSort(a, sizeof(a) / sizeof(a[0]));
		CountSort(a, sizeof(a) / sizeof(a[0]));
		HeapSort(a, sizeof(a) / sizeof(a[0]));
		*/
		int k = 0;
		for (k = 0; k < (sizeof(a) / sizeof(a[0])); k++)
		{
			printf("%d ", a[k]);
		}

		return 0;
	}

//
//
//
////void TestSortOP()
////{
////	const int n = 1000000;
////	int* a1 = (int*)malloc(sizeof(int)*n);
////	int* a2 = (int*)malloc(sizeof(int)*n);
////	int* a3 = (int*)malloc(sizeof(int)*n);
////	int* a4 = (int*)malloc(sizeof(int)*n);
////	int* a5 = (int*)malloc(sizeof(int)*n);
////	int* a6 = (int*)malloc(sizeof(int)*n);
////	int* a7 = (int*)malloc(sizeof(int)*n);
////	int* a8 = (int*)malloc(sizeof(int)*(n + 1));
////
////	srand(time(0));
////	for (int i = 0; i < n; ++i)
////	{
////		a1[i] = rand();
////		a2[i] = a1[i];
////		a3[i] = a1[i];
////		a4[i] = a1[i];
////		a5[i] = a1[i];
////		a6[i] = a1[i];
////		a7[i] = a1[i];
////		a8[i] = a1[i];
////	}
////	a8[n] = 100000000;
////
////	size_t begin1 = clock();
////	//InsertSort(a1, n);
////	size_t end1 = clock();
////	printf("%u\n", end1 - begin1);
////
////	size_t begin2 = clock();
////	ShellSort(a2, n);
////	size_t end2 = clock();
////	printf("%u\n", end2 - begin2);
////
////	size_t begin3 = clock();
////	//SelectSort(a3, n);
////	size_t end3 = clock();
////	printf("%u\n", end3 - begin3);
////
////	size_t begin4 = clock();
////	HeapSort(a4, n);
////	size_t end4 = clock();
////	printf("%u\n", end4 - begin4);
////
////	size_t begin5 = clock();
////	//BubbleSort(a5, n);
////	size_t end5 = clock();
////	printf("%u\n", end5 - begin5);
////
////	size_t begin6 = clock();
////	QuickSort(a6, 0, n - 1);
////	size_t end6 = clock();
////	printf("%u\n", end6 - begin6);
////
////	size_t begin7 = clock();
////	MergeSort(a7, n);
////	size_t end7 = clock();
////	printf("%u\n", end7 - begin7);
////
////	size_t begin8 = clock();
////	CountSort(a8, n + 1);
////	size_t end8 = clock();
////	printf("%u\n", end8 - begin8);
////}
