class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int daynum[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        vector<string> week={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        int start=4;//因为1971年的1月1日是星期五
        int sum=day;
        //年
         for(int i=1971;i<year;i++)
        {
           sum+=yearsNum(i);
        }
        //计算几月的第几天
        for(int i=1;i<month;i++)
        {
            sum+=daynum[i];
        }
        if(IsLeapyear(year)&&month>=3)
           {
            sum++;
           }
        
        sum=sum%7;
        int k=(sum+start)%7;
        return week[k];
        
    }
    bool IsLeapyear(int year)
    {
        bool flag=((year%4==0 && year%100!=0)||(year%400==0));
           return flag; 
    }
    int yearsNum(int year)
    {
        if(IsLeapyear(year))
            return 366;
        else
            return 365;
    }
};