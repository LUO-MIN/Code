int pos[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    void DFS(vector<vector<int>>& image, int sr,int sc,int row, int col, vector<vector<int>>& flag,int oldColor, int newColor)
    {
        image[sr][sc]=newColor;
        flag[sr][sc]=1;
       
        for(int k=0;k<4;k++)
        {
            int nx=sr+pos[k][0];
            int ny=sc+pos[k][1];
            
            if(nx<0 || nx>=row || ny<0 || ny>=col)
            {
                continue;
            }
            
            if(image[nx][ny]==oldColor && flag[nx][ny]==0)
            {
                DFS(image,nx,ny,row,col,flag,oldColor,newColor);
            }
        }      
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty())
        {
            return image;
        }
        
        int row=image.size();
        int col=image[0].size();
        
        vector<vector<int>> flag;//防止重复修改
        flag.resize(row);
        for(int i=0;i<row;i++)
        {
            flag[i].resize(col,0);
        }
        int oldColor=image[sr][sc];
        DFS(image,sr,sc,row,col,flag,oldColor, newColor);
        return image;
    }
    
};