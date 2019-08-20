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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* Node=new ListNode(0);//y因为头结点可能会被替换到新的位置，所以新建节点标记链表的头
        Node->next=head;
        ListNode* prev=head;
        ListNode* cur=head->next;

        
        while(cur)
        {
            if(cur->val < prev->val)
            {
                prev->next=cur->next;
                ListNode* one=Node;
                ListNode* two=Node->next;
            
             while(cur->val > two->val)
             {
                 one=one->next;
                 two=two->next;
             }
            one->next=cur;
            cur->next=two;
            cur=prev->next;
            }
            else{
                prev=prev->next;
                cur=cur->next;
            }
        
        }
        return Node->next;
    }
};