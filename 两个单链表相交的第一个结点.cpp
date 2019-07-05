/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1=headA;
        ListNode* p2=headB;
        
        int len1=getlen(headA);
        int len2=getlen(headB);
        
        
        while(len1 != len2){
        if(len1>len2)
        {
            p1=p1->next;
            len1--;
        }
         if(len1<len2)
        {
             p2=p2->next;
             len2--;
        }
    }

         while( p1 != p2)
         {
             p1=p1->next;
             p2=p2->next;
         }
          return p1;
    }
    
    int getlen(ListNode* head)
    {
        int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
        return count;
    }
};