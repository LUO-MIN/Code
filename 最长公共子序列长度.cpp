#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    string a,b;
    while(cin>>a>>b){
        
        if(a.size()< b.size()){
            swap(a,b);
        }
        
        int len1=a.size();
        int len2=b.size();
        int i,j,start=0,max=0;
        
        vector<vector<int> > mcs(len1+1,vector<int>(len2+1,0));
        for(i=1; i<=len1; i++)
        {
            for(j=1; j<=len2; j++)
            {
                if(a[i-1]==b[j-1])
                {
                    mcs[i][j]=mcs[i-1][j-1]+1;
                }
                if(mcs[i][j]>max)
                {
                    max=mcs[i][j];
                    start=i-max;
                }
            }
        }
        a = a.substr(start, max);
        cout<<a.size()<<endl;
    }
    return 0;
}