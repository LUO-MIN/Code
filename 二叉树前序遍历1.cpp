 /**

- Definition for a binary tree node.

- struct TreeNode {

- int val;

- struct TreeNode *left;

- struct TreeNode *right;

- };
  */
  /**

- Return an array of size *returnSize.

- Note: The returned array must be malloced, assume caller calls free().
  */

   /*算法思想：
    1.判断树是否为空

  - 2.计算节点个数（用递归根节点的方法计算）

  - 3.递归遍历节点的值，同样的要对树进行判空

  - 前中后序递归遍历方法相同，只不过改变左右子树的遍历顺序
*/

  int* preorderTraversal(struct TreeNode* root, int* returnSize) {
  *returnSize=GetTreeSize(root);
  //定义一个指针变量指向二叉树的结点
  int* array=(int*)malloc(*returnSize*sizeof(int));
  //动态开辟一个指针数组，存放节点个数个指针变量，数组元素对应指向对应结点
  int index=0;
  _preorderTraversal(root,array,&index);//遍历二叉树的函数。
  return array;
  }

int GetTreeSize(struct TreeNode* root)
//计算二叉树节点个数
{
    if(root==NULL)//如果为空树，节点个数为零
    {
        return 0;
    }
    
    return GetTreeSize(root->left)+GetTreeSize(root->right)+1;
    //递归求左子树和右子树的结点个数
}

void  _preorderTraversal(struct TreeNode* root,int* array,int *pIndex)
{


if(root==NULL)//判断树是否为空
{
    return NULL;
}
else
{
    array[*pIndex]=root->val;//依次访问二叉树的结点
    ++(*pIndex);
 
}

 _preorderTraversal(root->left,array,pIndex);
 _preorderTraversal(root->right,array,pIndex);
```

}