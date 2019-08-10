/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
利用队列和二维数组，一维数组来存储结点
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> tree_vec; 
       
        queue<Node*> q;  //注意队列中的数据类型，存储的是树节点，不是值
        if(root)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> rowNode;
            while(sz--){
            Node* cur=q.front();
            q.pop();
            rowNode.push_back(cur->val);
            for(auto &child:cur->children)
            {
                if(child)
                {
                     q.push(child);
                }
            }
          }
           tree_vec.push_back(rowNode); 
        }
        return tree_vec;
    }
};