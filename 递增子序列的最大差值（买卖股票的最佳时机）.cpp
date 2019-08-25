class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        
        int sum=0;
        int maxsum=0;
          for(int i=1;i<prices.size();i++)
          {
             for(int j=i-1;j>=0;j--)
             {
                sum=prices[i]-prices[j];
                maxsum=max(sum,maxsum);
             }
           } 
            return maxsum;
      
    }
};