//迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       //当链表只有一个结点或者链表为空的时候
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
    
        ListNode* prev=NULL;
        ListNode* cur=head    ;
        
        while(cur)
        {
         ListNode* _next=NULL;
         _next=cur->next;
         cur->next=prev;
        
        prev=cur;
        cur=_next;
        
        } 

        return prev;
    }
};


//引入中间结点交换结点位置
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead=NULL;  //创建一个新节点，将它置为空。
        ListNode* cur=head;            //将头结点置为cur

  while(cur)   // 当头节点不为空，即链表不为空
  {
      
      ListNode* next=cur->next;   //将next置为头结点的下一个
      cur->next=newhead;
      newhead=cur;
      cur=next;
  }
  return newhead;
  }
};