#include<iostream>
#include<string>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
     string str;
     while (cin >> str)
     {
          stack<char> s;
          for (int i = 2; i < str.size(); i++)
          {
              if (str[i] != str[0])
              {
                  s.push(str[i]);
              }
             else
              {
                  if (s.empty())
                   {
                       continue;
                   }
                   else{
                        s.pop();
                   }
              }
          }
          string a;
         while (!s.empty())
          {
             a += s.top();
              s.pop();
          }
          reverse(a.begin(), a.end());
         for (size_t i = 0; i < a.size(); i++)
          {
              cout << a[i];
          }
     }
     return 0;
}