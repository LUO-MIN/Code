/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//设置pos表示四个方向
int pos[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
class Solution {
public:
    void _slove(int x,int y, vector<vector<char>> &board,int row,int col)
    {
        //设当前位置的图案为“#”
        board[x][y]='#';
        //往四个方向查看是否是‘O’
        for(int k=0;k<4;k++)
        {
            int nx=x+pos[k][0];
            int ny=y+pos[k][1];
            
            //如果越界，不处理
            if(nx<0 || nx>=row || ny<0 || ny>=col)
            {
                continue;
            }
            
            if(board[nx][ny]!='#' && board[nx][ny]!='X')//说明等于‘O’,且与当前‘O’连通,将它标记成‘#’
            {
                _slove(nx,ny,board,row,col);
            }
          }
        }    
    
    void solve(vector<vector<char>>& board) {
        if(board.empty())
        {
            return;
        }
       int row=board.size();
       int col=board[0].size();
      //与边界连通的位置不变，那么先找到与边界连通的‘O’，然后并标记出来，即第一行，最后一行，第一列，最后一列
        
        //第一行，最后一行
        for(int i=0;i<col;i++)
        {
            if(board[0][i]=='O')
            {
                _slove(0,i,board,row,col);
            }
            if(board[row-1][i]=='O')
            {
                _slove(row-1,i,board,row,col);
            }
        }
        
        //第一列，最后一列
            for(int j=0;j<row;j++)
            {
                if(board[j][0]=='O')
                {
                    _slove(j,0,board,row,col);
                }
                if(board[j][col-1]=='O')
                {
                    _slove(j,col-1,board,row,col);
                }
            }
        
        //搜索完毕之后，将除过‘#’标记的位置都变成‘X’,在将‘#’，变成‘O’
        for(int i=0;i<row;i++)
        {
           for(int j=0;j<col;j++)
           {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
            }
        }
    }
    
    
 
};