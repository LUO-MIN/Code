//C++
struct ListNode* removeElements(struct ListNode* head, int val) {
      struct ListNode* cur=head;
        struct ListNode* prev=NULL;
        
        while(cur)
        {
            if(cur->val==val)
            {
               struct ListNode* next=cur->next;
               if(prev==NULL)
               {
                    head=cur->next;
               }
               else
               {
                   prev->next=cur->next;
                }
            
              free(cur);
              cur = next;
            }
             else
           {
             prev=cur;
             cur=cur->next;
             }
       }
   
      return head;
}

//C
struct ListNode* removeElements(struct ListNode* head, int val) {
      struct ListNode* cur=head;
        struct ListNode* prev=NULL;
        
        while(cur)
        {
            if(cur->val==val)
            {
               struct ListNode* next=cur->next;
               if(prev==NULL)
               {
                    head=cur->next;
               }
               else
               {
                   prev->next=cur->next;
                }
            
              free(cur);
              cur = next;
            }
             else
           {
             prev=cur;
             cur=cur->next;
             }
       }
   
      return head;
}