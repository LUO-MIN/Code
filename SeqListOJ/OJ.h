#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* removeElement(struct ListNode* head, int val);

int TestOJ();