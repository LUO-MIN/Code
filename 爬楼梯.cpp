class Solution {
public:
    int climbStairs(int n) {
        //F(1)=1;F(2)=2;F(i)=F(i-1)+F(i-2)
        long long f=0;
        long long f1=1;
        long long f2=2;
        
        if(n<=0)
        {
            return 0;
        }
        else if(n==1)
        {
            return f1;
        }
        else if(n==2)
        {
            return f2;
        }
        
        while(n>2){
            f=f1+f2;
            f1=f2;
            f2=f;
            n--;
        }
        
        return f;
    }
};