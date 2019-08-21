class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        
        int slow=0;
        int fast=1;
        for(int fast=1;fast<nums.size();fast++)
        {
            if(nums[slow]!=nums[fast])
            {
                  slow++;
                  nums[slow]=nums[fast];
            }
           //当两数相等时，fast一直向前走，找到不相等的之后，将相等数字覆盖
        }
        return slow+1;//
    }
};