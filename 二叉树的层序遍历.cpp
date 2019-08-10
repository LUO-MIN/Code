/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> tree_vec;
        queue<TreeNode*> q;
        if(root)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            vector<int> row;
            int sz=q.size();
             while(sz--)
            {
            TreeNode* cur=q.front();
            q.pop();
            row.push_back(cur->val);
           
             if(cur->left)
                q.push(cur->left);
              if(cur->right)
                q.push(cur->right);
            }
            tree_vec.push_back(row);
        }
        return tree_vec;
    }
};