https://www.nowcoder.com/questionTerminal/1046cd038f7a4b04b2b77b415973de1c
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s,t;
    while(cin>>s>>t){
        int count=0;
        size_t pos=0;
        while((pos=s.find(t,pos))!= string::npos)
        {
            pos += t.size();
            count++;
        }
        cout<< count <<endl;
    }
}