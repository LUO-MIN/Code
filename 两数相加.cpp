/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root=new ListNode(0);
        ListNode* cur=root;
        
        int flag=0;
        while(l1 || l2 || flag)
        {
            int tmp=0;
            if(l1 != nullptr)
                tmp=tmp+l1->val;
            if(l2 != nullptr)
                tmp=tmp+l2->val;
            //此时的tmp是链表的第一个结点值的和，即使有一个链表结点为空，也不会有影响
            tmp+=flag;
            
            flag=tmp/10;
            tmp=tmp%10;
            
            //新建结点的val部分等于tmp
            ListNode* _next=new ListNode(tmp);

            cur->next=_next;
            cur=cur->next;//或者cur=_next;
            
            l1=l1?l1->next:nullptr;
            l2=l2?l2->next:nullptr;
            
        }
        return root->next;       
    }

};

//递归方法
