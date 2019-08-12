class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
		for (auto num : nums) {
			if (arr.empty() || num > arr.back()) {
				arr.push_back(num);
			}
			else {
				*(lower_bound(arr.begin(), arr.end(), num)) = num;
			}
		}
		return arr.size();
    }
};

//动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        
        int maxlen=-1;
        int len=nums.size();
        vector<int> dp(len);
        
        for(int i=0;i<len;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]&&dp[j]+1>dp[i])
                    dp[i]=dp[j]+1;
            }
             maxlen=max(maxlen,dp[i]);
        }
         return maxlen;
    }
};