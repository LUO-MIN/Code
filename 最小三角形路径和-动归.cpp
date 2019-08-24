class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
        {
            return 0;
        }
        
        vector<vector<int>> dp(triangle);
        int row=triangle.size();
        for(int i=1;i<row;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else if(i==j)
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]);
                }
                dp[i][j]= dp[i][j]+triangle[i][j];
            }
        }
        int minsum=dp[row-1][0];
        for(int i=1;i<row;i++)
        {
            minsum=min(dp[row-1][i],minsum);
        }
        return minsum;
    }
};