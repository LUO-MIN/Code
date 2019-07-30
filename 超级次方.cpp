class Solution {
public:
    int superPow(int a, vector<int>& b) {
       long long result=1;
       for(int i=0;i<b.size();i++)
       {
           result=mypow(result,10)*mypow(a,b[i])%1337;
       }
        return result;
    }
    int mypow(int m,int n)
    {
       if(n==0)
       {
           return 1;
       }
        else if(n==1)
        {
            return m%1337;
        }
        
      return mypow(m%1337, n>>1)*mypow(m%1337,n-(n>>1))%1337;
    }
       
};