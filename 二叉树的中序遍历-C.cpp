int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize=GetTreeSize(root);
    int* array=(int*)malloc(*returnSize*sizeof(int));
    int index=0;
    _inorderTraversal(root,array,&index);
    return array;
}

int GetTreeSize(struct TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    return GetTreeSize(root->left)+GetTreeSize(root->right)+1;
}

void _inorderTraversal(struct TreeNode* root,int* array,int *pIndex)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        _inorderTraversal(root->left,array,pIndex);
        array[*pIndex]=root->val;
        ++(*pIndex);
    }
    
     _inorderTraversal(root->right,array,pIndex);
}