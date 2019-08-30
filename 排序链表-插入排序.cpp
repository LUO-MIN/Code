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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* Node=new ListNode(-1);
        while(head)
        {
            ListNode* cur=Node;
            while(cur->next && cur->next->val<head->val)
            {
                cur=cur->next;
            }
            ListNode* last=head;
            head=head->next;
            
            last->next=cur->next;
            cur->next=last;
        }
        return Node->next;
    }
};