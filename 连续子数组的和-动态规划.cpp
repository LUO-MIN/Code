class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        
        int sum=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum=max(sum+nums[i],nums[i]);
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};