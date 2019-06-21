/**
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //链表只有的头结点为空或者只有一个结点
        if(head == NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode* cur = head;
        while(cur->next)
        {
            if(cur->val == cur->next->val)
            {
               cur->next=cur->next->next;
               
            }
            else
            {
                cur=cur->next;
            }
        }
        return head;
    }
};