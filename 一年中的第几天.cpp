class Solution {
public:
    int dayOfYear(string date) {
        if(date.empty())
        {
            return 0;
        }
        
        int year=0;
        int month=0;
        int day=0;
        for(int i=0;i<4;i++)
        {
            year=year*10+date[i]-'0';
        }
        for(int i=5;i<7;i++)
        {
            month=month*10+date[i]-'0';
        }
        for(int i=8;i<10;i++)
        {
            day=day*10+date[i]-'0';
        }
        int time[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        int sum=day;
        
        for(int i=1;i<=month-1;i++)
        {
            sum+=time[i];
        }
         
        if(month>=3 && IsLeapyear(year))
        {
            sum++;
        }
        
        return sum;
    }
    
    bool IsLeapyear(int year)
    {
        bool flag=((year%4==0 && year%100!=0)||(year%400==0));
            return flag;
    }
};