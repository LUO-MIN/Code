class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty())
        {
            return;
        }
        
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                res.push_back(nums[i]);
            }
        }
        
        while(count--)
        {
            res.push_back(0);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=res[i];
        }
    }
};