#include "List.h"

//带头双向循环链表
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	assert(node);
	node->_data=x;
	node->_next = NULL;
	node->_prev = NULL;

	return node;
}

void ListInit(List* plist)
{
	assert(plist);
	plist->_head = BuyListNode(0);
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListDestory(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
	plist->_head = NULL;
}


void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;

	ListNode* tail = head->_prev;
	ListNode* newnode = BuyListNode(x);

	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = head;
	head->_prev = newnode;

	//ListInsert(plist->_head,x);
}
void ListPushBack(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* prev = tail->_prev;

	prev->_next = head;
	head->_prev = prev;

	free(tail);
	//ListErase(plist->_head->_prev);
}
void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* newnode = BuyListNode(x);

	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = next;
	next->_prev = newnode;

	//ListInsert(plist->_head->_next,x);
}
void ListPopFront(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* next = head->_next;
	ListNode* nextnext = next->_next;

	if (head == next)
	{
		return;

	}
	head->_next = nextnext;
	nextnext->_prev = head;
	free(next);
	next = NULL;

	//ListErase(plist->_head->_next);
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}

		cur = cur->_next;
	}
	return NULL;
}
// 在pos的前面进行插入 
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = newnode;

}
// 删除pos位置的节点 
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}
void ListRemove(List* plist, LTDataType x)
{
	


}

void ListPrint(List* plist)
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}

	printf("<=>\n");
}
