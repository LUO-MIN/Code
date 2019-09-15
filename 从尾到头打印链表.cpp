/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> list;
        if(head==NULL)
        {
            return list;
        }
        if(head->next==NULL)
        {
            list.push_back(head->val);
        }
        
        ListNode* cur=head;
        while(cur)
        {
            list.push_back(cur->val);
            cur=cur->next;
        }
        reverse(list.begin(),list.end());
        return list;
    }
};


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        vector<int> tmp;
        if(head==NULL)
        {
            return tmp;
        }
        
        ListNode* cur=head;
        while(cur)
        {
            s.push(cur->val);
            cur=cur->next;
        }
        
        
        while(!s.empty())
        {
           tmp.push_back(s.top());
            s.pop();
        }
        return tmp;
    }
};