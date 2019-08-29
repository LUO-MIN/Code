class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty())
        {
            return 0;
        }
        
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            if(obstacleGrid[i][0])
              break;
            else 
              dp[i][0]=1;
        }
         for(int j=0;j<col;j++)
         {
            if(obstacleGrid[0][j])
                break;
             else 
               dp[0][j]=1;
         }
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[row-1][col-1];
    }
};