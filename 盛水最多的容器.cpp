class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int sum=0;
        int maxsum=0;
        while(start<end)
        {
            int len=min(height[start],height[end]);
            sum=len*(end-start);
            maxsum=max(maxsum,sum);
            if(height[start]<height[end])
                start++;
            else 
                end--;
        }
        return maxsum;
    }
};