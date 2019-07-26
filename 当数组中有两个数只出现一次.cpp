class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2)
       {
        return;
       }
        
        int flag=0;
        for(int i=0;i<data.size();i++)
        {
            flag=flag^data[i];
        }
        
         int index=0;
        while((flag&1)==0)
        {
            flag=flag>>1;
            index++;
        }
         *num1=0;
         *num2=0;
         for(int i=0;i<data.size();i++)
         {
             if(BitIs1(data[i],index))
                 *num1^=data[i];
             else
                 *num2^=data[i];
         }
    }
    bool BitIs1(int x, int index)
    {
           x=x>>index;
           return x&1;
    }

};