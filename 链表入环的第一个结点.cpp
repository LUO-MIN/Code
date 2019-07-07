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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;
        
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
    
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }
        
        if(prev==slow)
        {
            return slow;
        }
        
        while(prev !=NULL && slow != NULL)
        {
            prev=prev->next;
            slow=slow->next;
            if(prev==slow)
            {
                return prev;
            }
        }
        
        return NULL;
        
        
    }
};