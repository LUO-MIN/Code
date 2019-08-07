class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        if(n==0 || m==0)
        {
            return 0;
        }
        
        int i=0;
        int j=0;
        vector<vector<int> > v(n+1,vector<int>(m+1,0));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(A[i-1]==B[j-1])
                {
                    v[i][j]=v[i-1][j-1]+1;
                }
                else{ 
                    if(v[i-1][j]>=v[i][j-1])
                    {
                       v[i][j]=v[i-1][j];
                    }
                    else{
                       v[i][j]=v[i][j-1];
                    }
                }  
            }
        }  
        return v[n][m];
    }
};