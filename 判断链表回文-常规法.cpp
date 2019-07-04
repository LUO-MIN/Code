class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        if(A==NULL)
        {
            return false;
        }
        if(A->next==NULL)
        {
            return true;
        }
        
        ListNode* slow=A;
        ListNode* fast=A;
        ListNode* cur=A;
        //用快慢指针找到中间结点
        while(fast!= NULL && fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //逆置后半段链表
        ListNode* last=NULL;
        ListNode* prev=NULL;
        while(slow != NULL){
        last=slow->next;
        slow->next=prev;
            
        prev=slow;
        slow=last;
       }
       
        while(cur!=NULL && prev!=NULL)
        {
            if(cur->val == prev-> val)
            {
                cur=cur->next;
                prev=prev->next;
            }
            else{
                return false;
            }
        }
        return true;   
    }
};