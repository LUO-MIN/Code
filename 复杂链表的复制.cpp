/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        copyNode(head);
        copyRandom(head);
        
        //分离链表
        Node* src=head;
        Node* deshead=NULL;
        Node* des=NULL;
        
        if(src!=NULL)
        {
            deshead=src->next;
               des=src->next;
            src->next=des->next;
            src=src->next;
        }
        
        while(src != NULL)
        {
            des->next=src->next;
            des=des->next;
             src->next=des->next;
            src=src->next;
        }
        return deshead;
    }
    
    //复制结点
    void copyNode(Node* head)
    {
        Node* src=head;
        while(src != NULL)
        {
            Node* des=new Node();
            des->val=src->val;//复制源节点的值
            des->next=src->next;//复制源节点的next指针
            des->random=NULL;
            src->next=des;
            src=des->next;
            
        }
    }
    
    //复制随机指针
    void copyRandom(Node* head)
    {
        Node* src=head;
        while(src != NULL){
           Node* des=src->next;
           if(src->random != NULL)
           {
            des->random=src->random->next;
           }
             src=des->next;
        }
        
    }
    
    
};