#include "SList.h"

//单链表实现
void SListPrint(SList* plist)
{
	SListNode* cur = plist->_head;
	while (cur != plist->_tail)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void SListInit(SList* plist)//初始化
{
	assert(plist);
	plist->_head = plist->_tail = NULL;

}

void SListDestory(SList* plist)//链表的销毁
{
	SListNode* cur;
	assert(plist);
	cur = plist->_head;
	while (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);

		cur = next;
	}

	plist->_head = plist->_tail = NULL;
}


SListNode* BuySListNode(SLTDataType x)
{
	SListNode* node = malloc(sizeof(SListNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;

	return node;
}



void SListPushBack(SList* plist, SLTDataType x)
{
	
	assert(plist);

	if (plist->_tail == NULL)
	{
		plist->_head =plist->_tail = BuySListNode(x);
	}
	else
	{
		SListNode* newnode = BuySListNode(x);
		plist->_tail->_next = newnode;
		plist->_tail = newnode;

	}
}
void SListPopBack(SList* plist)
{
	SListNode* prev, *tail;
	assert(plist);

	prev = NULL;
	tail = plist->_head;
	if (tail->_next==NULL)
	{
		free(tail);
		plist->_head = NULL;

	}
	else
	{
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		prev->_next = NULL;
	}
}
void SListPushFront(SList* plist, SLTDataType x)
{
	SListNode* newnode;
	assert(plist);

	newnode = BuySListNode(x);
	newnode->_next = plist->_head;
	plist->_head = newnode;
}


void SListPopFront(SList* plist)
{
	SListNode* next;
	assert(plist);

	next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}

	return NULL;
}
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* next, *newnode;
	assert(pos);

	next = pos->_next;
	newnode = BuySListNode(x);
	pos->_next = newnode;
	newnode->_next = next;
}
// 删除pos后面位置的值
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->_next == NULL)
	{
		return;
	}
	SListNode* next = pos->_next;
	pos->_next = next->_next;
	free(next);
	next = NULL;

}
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	if (plist->_head->_data == x)
	{
		SListPopFront(plist);
		return;
	}
	SListNode* prev;
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			prev->_next = cur->_next;
			free(cur);
			cur = NULL;
			break;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}



void TestSList()
{
	SList sl;
	SListInit(&sl);
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);

	SListPopBack(&sl);
	
	

	SListDestory(&sl);


	SListPrint(&sl);

	SListDestory(&sl);
}
