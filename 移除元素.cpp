class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
        {
            return 0;
        }
       
        int slow=0;
        int fast=0;
        for(fast=0;fast<nums.size();fast++)
        {
            if(nums[fast]!=val)
            {
              
                nums[slow]=nums[fast];
                 slow++;
            }
           
        }
        return slow;//表示slow走过的元素
    }
};