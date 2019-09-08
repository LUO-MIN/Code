class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
        {
            return 0;
        }
        
        int row=grid.size();
        int col=grid[0].size();
        
        int maxcount=0;
        int count=0;
        
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
                if(grid[i][j]==1 && flag[i][j]==0)
                {
                    count=1+dfs(i,j,flag,grid,row,col,count);//加一表示当前岛屿的面积
                    maxcount=max(maxcount,count);
                    count=0;
                }
            }
        }
        return maxcount;
    }
    
    int dfs(int x,int y,vector<vector<int>> &flag,vector<vector<int>> &grid,int row,int col,int &count)
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
            
            if(grid[nx][ny]==1 && flag[nx][ny]==0)
            {
                count++;
                dfs(nx,ny,flag,grid,row,col,count);
            }
        }
        return count;
    }
};