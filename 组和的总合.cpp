class Solution {
public:
    void dfs(vector<int>& candidates,vector<vector<int>> &res,vector<int> &tmp,int cursum,int prev,int target)
    {
        if(cursum>=target)
        {
            if(cursum==target)
                res.push_back(tmp);
            return;
        }
        for(int i=prev;i<candidates.size();i++)
        {
            if(candidates[i]>target)
            {
                continue;
            }
            tmp.push_back(candidates[i]);
            dfs(candidates, res,tmp,cursum+candidates[i],i,target);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        if(candidates.empty())
        {
            return res;
        }
        int cursum=0;
        
        dfs(candidates,res,tmp,cursum,0,target);
        return res;
    }
};