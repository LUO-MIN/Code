class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
       if(pHead==NULL || pHead->next==NULL)
       {
           return pHead;
       }
        ListNode* head=new ListNode(0);
        head->next=pHead;
        ListNode* prev=head;
        ListNode* cur=head->next;
      while(cur){
        if(cur->next && cur->val==cur->next->val)
        {
            while(cur->next && cur->val==cur->next->val)
            {
                 cur=cur->next;
            }
            prev->next=cur->next;
            cur=cur->next;
        }
        else{
            prev=prev->next;
            cur=cur->next;
        }
      }
        return head->next;
    }
};