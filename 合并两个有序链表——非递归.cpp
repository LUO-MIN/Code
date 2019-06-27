class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        
        ListNode* phead=new ListNode(-1);
        ListNode* prev=phead;
       while(l1 !=NULL && l2 != NULL)
       {
           if(l1->val <= l2->val)
           {
               prev->next=l1;;
               l1 = l1->next;
           }
           else
           {
               prev->next=l2;
               l2 = l2->next;
           }
           prev=prev->next;
       }
       
        if(l1==NULL)
        {
            prev->next=l2;
        }
        if(l2==NULL)
        {
            prev->next=l1;
        }
        
        return phead->next;
    }
};