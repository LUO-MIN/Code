#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* reverseKlist(ListNode* head, int k)
{
    ListNode* begin=head;
    ListNode* end=head;
    ListNode* prev=head;
    for(int i=0;i<k;i++)
    {
        if(end!=NULL)
        {
            end=end->next;
        }
        else{
            return begin;
        }
    }
    ListNode* phead=begin;
    while(begin!=end)
    {
        ListNode* pnext=begin->next;
        begin->next=prev;
        prev=begin;
        begin=pnext;
    }
     
    phead->next=reverseKlist(end,k);
    return prev;
}

int main()
{
    vector<int> v;
    int k;
    int tmp;
    while(cin>>tmp)
    {
        v.push_back(tmp);
        if(getchar()=='\n')
        {
            break;
        }
    }
    cin>>k;
    
    ListNode* head=new ListNode(v[0]);
    ListNode* cur=head;
    for(int i=1;i<v.size();i++)
    {
        ListNode* node=new ListNode(v[i]);
        cur->next=node;
        cur=node;
    }
    
    ListNode* p=reverseKlist(head,k);
    while(p)
    {
        cout<<p->val <<" ";
         p=p->next;
    }
    return 0;

}