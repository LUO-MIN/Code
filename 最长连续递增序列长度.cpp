class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return nums.size();
        }
        
        int len=nums.size();
        int maxlen=-1;
        int count=1;
        
        for(int i=0;i<len-1;i++)
        {
              if(nums[i+1]>nums[i])
              {
                    count++;
              }
               else
               {
                    count=1;
               }
            maxlen=max(maxlen,count);
        }
        return maxlen;
    }
};