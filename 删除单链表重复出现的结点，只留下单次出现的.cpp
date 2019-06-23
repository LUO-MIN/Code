/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
       if(pHead==NULL || pHead->next==NULL)
       {
           return pHead;
       }
        
        ListNode* cur;
        if(pHead->val == pHead->next->val)
          {
             cur = pHead->next->next;
           while(cur && pHead->val==cur->val)
               cur=cur->next;
              return deleteDuplication(cur);
        }
        else
        {
               cur=pHead->next;
               pHead->next=deleteDuplication(cur);
               return pHead;
           }
    }
};