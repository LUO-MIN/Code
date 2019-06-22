/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//快慢指针法
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast != NULL  && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        
        }
        
        return slow;
    }
};