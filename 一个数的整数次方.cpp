    class Solution {
public:
    double myPow(double x, long long n) {
        //考虑指数为0或者底数为1的情况
        if(n==0 || x==1.0)
        {
            return 1.0;
        }
       
        //判断底数是否为0
        if(Isequal0(x))
        {
            return 0.0;
        }
    
        //指数为负
        if(n<0)
        {
           return 1/pow(x,-n);
        }
        else{
           return pow(x,n);
        }
       return 1.0;
    }
    double pow(double x, long long n)
    {
      double res=1.0;
       while(n)
       {
           if(n&1==1)
               res=res*x;
          n = n>>1;
           x=x*x;
       }
        return res;
    }
    bool Isequal0(double x)
    {
        if(abs(x-0.0)<0.0000001)
        {
            return true;
        }
        return false;
    }
};