#include <iostream>
using namespace std;

struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
    ListNode(int x): m_nKey(x),m_pNext(NULL){}
};

int findKnode(ListNode* head,int k)
{
    ListNode* fast=head;
    ListNode* slow=head;

    while(k-1)
    {
        fast=fast->m_pNext;
        k--;
    }
    
    while(fast!=NULL)
    {
        fast=fast->m_pNext;
        slow=slow->m_pNext;
    }
    return slow->m_nKey;
}

int main()
{
    ListNode* head=new ListNode(1);
    ListNode* tmp=head;
    for(int i=2;i<=7;i++)
    {
        ListNode* cur=new ListNode(i);
        tmp->m_pNext=cur;
        tmp=cur;
    }
    int k;
    cin>>k;
    
    ListNode* fast=head;
    ListNode* slow=head;

    while(k)
    {
        fast=fast->m_pNext;
        k--;
    }
    
    while(fast!=NULL)
    {
        fast=fast->m_pNext;
        slow=slow->m_pNext;
    }
    cout<<slow->m_nKey<<endl;
    return 0;
}