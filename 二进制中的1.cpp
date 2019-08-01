class Solution {
public:
    int hammingWeight(uint32_t n) {
      //最右一位&1法
        int count=0;
        while(n)
        {
            if(n & 1==1)
            {
                count++;
            }
            n=(n>>1);
        }
        return count;
    
        //n&n-1法
        int count=0;
        while(n)
        {
          count++;
         n=(n-1)&n;
        }
        return count;
    }
};