class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
        {
            return 0;
        }
        
        //用自底向上的方法
        vector<vector<int>> dp(triangle);
       int row=triangle.size();
        
        for(int i=row-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};