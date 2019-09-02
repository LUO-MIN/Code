class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.empty())
        {
            return false;
        }
        
        int sum=0;
        for(int i=1;i<nums.size();i++)
        {
            sum=nums[i];
            for(int j=i-1;j>=0;j--)
            {
                sum+=nums[j];
                if(k!=0 && sum%k==0)
                {
                    return true;
                }
                if(sum==0)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
};