/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool Symmetric(struct TreeNode* pLroot,struct TreeNode* pRroot)
{
    if(pLroot==NULL && pRroot==NULL)
    {
        return true;
    }
    if(pLroot==NULL || pRroot==NULL)
    {
        return false;
    }
   if(pLroot->val != pRroot->val)
    {
        return false;
    }
    return Symmetric(pLroot->right,pRroot->left)
        && Symmetric(pLroot->left,pRroot->right);
}


bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)
    {
        return true;
    }
    //int Lroot = 0;
    //int Rroot = 0;
    return Symmetric(root->left,root->right);
}

