class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
        {
            return -1;
        }
        
        return binaryfind(nums,0,nums.size()-1,target);
    }
    
    int binaryfind(vector<int>& nums, int left, int right, int target)
    {
        int mid=0;
        while(left <= right){
        mid=left+(right-left)/2;
        if(nums[mid]>target)
        {
           return binaryfind(nums,left,mid-1,target);
        }
        else if(nums[mid]<target)
        {
            return binaryfind(nums,mid+1,right,target);
        }
        else if(nums[mid]==target)
        {
            return mid;
        }
    }
        return -1;
    }
};