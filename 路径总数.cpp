class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0)
        {
            return 0;
        }
        if(m==1 || n==1)
        {
            return 1;
        }
         
        vector<vector<int>> dp(n, vector<int>(m,1));
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};