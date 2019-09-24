/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        //如果一个结点有右子树，那么它的下一个节点，就是右子树节点的左子节点（中序遍历）
        if(pNode==NULL)
        {
            return NULL;
        }
        
        TreeLinkNode* pnext=NULL;
        if(pNode->right!=NULL)
        {
            TreeLinkNode* pright=pNode->right;
            while(pright->left!=NULL)
                pright=pright->left;
            
            pnext=pright;
        }
        else if(pNode->next!=NULL){
            TreeLinkNode* cur=pNode;
            TreeLinkNode* parent=pNode->next;
            while(parent!=NULL && cur==parent->right)
            {
                cur=parent;
                parent=parent->next;
            }
            pnext=parent;
        }
        return pnext;
    }
};