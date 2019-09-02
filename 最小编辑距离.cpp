class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()&&word2.empty())
        {
            return 0;
        }
        if(word1.empty() && !word2.empty())
        {
            return word2.size();
        }
        if(!word1.empty() && word2.empty())
        {
            return word1.size();
        }
        
        int row=word1.size();
        int col=word2.size();
        
        vector<vector<int>> ch(row+1,vector<int>(col+1,0));
        for(int i=0;i<=row;i++)
        {
             ch[i][0]=i;
        }
        for(int j=0;j<=col;j++)
        {
            ch[0][j]=j;
        }
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(word1[i-1]==word2 [j-1])
                {
                    ch[i][j]=1+min(ch[i][j-1],ch[i-1][j]);
                    ch[i][j]=min(ch[i-1][j-1],ch[i][j]);
                }
                else{
                    ch[i][j]=1+min(ch[i-1][j], ch[i][j-1]);
                    ch[i][j]=min(ch[i][j],1+ch[i-1][j-1]);
                }
            }
        }
        return ch[row][col];
    }
};