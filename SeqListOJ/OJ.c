#include "OJ.h"


void ListInit(struct ListNode* head)
{

}

struct ListNode* removeElement(struct ListNode* head, int val)
{
	if (head == NULL)
	{
		return NULL;
	}

	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			struct ListNode* next = cur->next;
			if (prev == NULL)
			{
				head = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}

			free(cur);
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}





int TestOJ()
{

	
	return 0;
}