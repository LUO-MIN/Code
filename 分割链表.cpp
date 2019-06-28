/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead==NULL)
        {
            return pHead;
        }
        ListNode* smallhead=new ListNode(0);
        ListNode* prev=smallhead;
        ListNode* bighead=new ListNode(0);
        ListNode* last=bighead;
        ListNode* cur=pHead;
        
        while(cur != NULL)
        {
            if(cur->val<x)
            {
                prev->next=cur;
                prev=prev->next;
            }
            else
            {
                last->next=cur;
                last=last->next;
            }
            cur=cur->next;
        }
        
        last->next=NULL;
        prev->next=bighead->next;
        return smallhead->next;
    }
};