/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
       
        if(pListHead==NULL || k==0)
        {
            return NULL;
        }
         
        ListNode* cur=pListHead;
        ListNode* prev=pListHead;
        for(unsigned int i=0; i<k-1;i++)
        {
            if(cur->next != NULL)
              cur=cur->next;
            else
                return NULL;
        }
         
        while(cur->next!=NULL)
        {
            cur=cur->next;
            prev=prev->next;
        }
        return prev;
    }
};