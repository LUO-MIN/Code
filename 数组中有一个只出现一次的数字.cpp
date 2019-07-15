class Solution {
public:
    //运用异或，任何数字异或它自己都等于0，留下最后的就是只出现一次的
    int singleNumber(vector<int>& nums) {
     
        int flag=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            flag=flag^nums[i];
        }
        
        return flag;
    }
};