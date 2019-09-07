class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        {
            return 0;
        }
        
        int sum=0;
        int row=grid.size();
        int col=grid[0].size();
        
        vector<vector<int>> flag;
        flag.resize(row);
        for(int i=0;i<row;i++)
        {
            flag[i].resize(col,0);
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1'&& flag[i][j]==0)
                {
                    sum++;
                    dfs(i,j,flag,grid,row,col);
                }
            }
        }
        return sum;
    }
    void dfs(int x, int y,vector<vector<int>> &flag,vector<vector<char>>& grid,int row, int col)
    {
        flag[x][y]=1;
        int pos[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++)
        {
            int nx=x+pos[k][0];
            int ny=y+pos[k][1];
            
            if(nx<0 || nx>=row || ny<0 || ny>=col)
            {
                continue;
            }
            if(grid[nx][ny]=='1'&&flag[nx][ny]==0)
            {
                dfs(nx,ny,flag,grid,row,col);
            }
        }
    }
};