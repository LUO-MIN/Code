/*
有 n 个物品和一个大小为 m 的背包. 给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.
问最多能装入背包的总价值是多大?

状态：
 F(i, j): 前i个物品放入大小为j的背包中所获得的最大价值
状态递推：对于第i个商品，有一种例外，装不下，两种选择，放或者不放
 如果装不下：此时的价值与前i-1个的价值是一样的
 F(i,j) = F(i-1,j)
 如果可以装入：需要在两种选择中找最大的
 F(i, j) = max{F(i-1,j), F(i-1, j - A[i]) + V[i]}
 F(i-1,j): 表示不把第i个物品放入背包中， 所以它的价值就是前i-1个物品放入大小为j的背包的最大价值
 F(i-1, j - A[i]) + V[i]：表示把第i个物品放入背包中，价值增加V[i],但是需要腾出j - A[i]的大小放
第i个商品
初始化：第0行和第0列都为0，表示没有装物品时的价值都为0
 F(0,j) = F(i,0) = 0
返回值：F(n,m)

*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        if(m<1 || A.empty() || V.empty())
        {
            return 0;
        }
        
        int row=A.size()+1;//行列分别加1，方便初始化
        int col=m+1;
        vector<vector<int>> dp;
        dp.resize(row);
        for(int i=0;i<row;i++)
        {
            dp[i].resize(col,0);
        }
        
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(A[i-1]>j)//说明装不下
                {
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-A[i-1]]+V[i-1]);
                }
            }
        }
        return dp[row-1][col-1];
    }
};