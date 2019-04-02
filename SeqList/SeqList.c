#include "SeqList.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	if (capacity == 0)
	{
		psl->_a = NULL;
		psl->_capacity = 0;
		psl->_size = 0;

	}
	else
	{
		psl->_capacity = capacity;
		psl->_size = 0;
		psl->_a = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
		assert(psl->_a);
	}
}

void SeqListDestory(SeqList* psl)
{
	assert(psl);
	free(psl->_a);
	psl->_a = NULL;
	psl->_size = psl->_capacity = 0;
}

void CheckCapacity(SeqList* psl)
{
	if (psl->_size == psl->_capacity)
	{
		SLDataType* tmp;
		if (psl->_capacity == 0)
		{
			psl->_capacity = 2;
		}
		tmp = realloc(psl->_a, psl->_capacity*2*sizeof(SLDataType));
		assert(tmp);
		psl->_a = tmp;
		psl->_capacity *= 2;
	}
}


void SeqListPushback(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->_a[psl->_size] = x;
	psl->_size++;
	//SeqListInsert(psl, psl->_size, x);
}

void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	if (psl->_size > 0)
	{
		psl->_size--;
	}
	//SeqListErase(psl, psl->_size - 1);
}

void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	if (psl->_size > 0)
	{
		int start = 0;
		while (start < (psl->_size - 1))
		{
			psl->_a[start] = psl->_a[start + 1];
			++start;
		}
		psl->_size--;
	}
	//SeqListErase(pls, 0);
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	int end;
	assert(psl&&pos <= psl->_size);
	CheckCapacity(psl);
	end = psl->_size - 1;
	while (end >= (int)pos)
	{
		psl->_a[end + 1] = psl->_a[end];
		--end;
	}
	psl->_a[pos] = x;
	psl->_size++;
}

void SeqListErase(SeqList* psl, size_t pos)
{
	int start;
	assert(psl&&pos < psl->_size);
	start = pos;
	while (start < psl->_size - 1)
	{
		psl->_a[start] = psl->_a[start + 1];
		++start;
	}
	--psl->_size;
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	int i = 0;
	assert(psl);
	for (; i < psl->_size; ++i)
	{
		if (psl->_a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void seqListRemove(SeqList* psl, SLDataType x)
{
	int pos;
	assert(psl);
	pos = SeqListFind(psl, x);
	if (pos != -1)
	{
		SeqListErase(psl, pos);
	}
}

void SeqListPrint(SeqList* psl)
{
	size_t i = 0;
	assert(psl);
	for (; i < psl->_size; ++i)
	{
		printf("%d ", psl->_a[i]);
	}
	printf("\n");
}



void SeqListBubbleSort(SeqList* psl)
{
	int begin, end;
	assert(psl);

	end = psl->_size;

	while (end > 0)
	{
		int exchange = 0;
		begin = 1;
		while (begin < end)
		{
			if (psl->_a[begin - 1]>psl->_a[begin])
			{
				SLDataType tmp = psl->_a[begin];
				psl->_a[begin - 1] = psl->_a[begin];
				psl->_a[begin] = tmp;

				exchange = 1;
			}

			++begin;
		}

		if (exchange == 0)
		{
			break;
		}

		-end;
	}

}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	int  begin, end;
	assert(psl);

	begin = 0;
	end = psl->_size - 1;

	while (begin <= end)
	{
		int mid = begin + (end - begin) / 2;
		if (psl->_a[mid] > x)
		{
			end = mid + 1;
		}
		else if (psl->_a[mid] < x)
		{
			begin = mid + 1;
		}
		else if (psl->_a[mid] < x)
		{
			begin = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}



void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	int index, start;
	assert(psl);

	index = 0;
	start = 0;
	while (start < psl->_size)
	{
		if (psl->_a[start] != x)
		{
			psl->_a[index] = psl->_a[start];
			++index;
			++start;
		}
		else
		{
			++start;
		}
	}

	psl->_size = index;
}

void TestSeqList()
{
	SeqList s1;
	SeqListInit(&s1, 0);

}