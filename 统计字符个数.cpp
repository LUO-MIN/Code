#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
     string str;
     while (cin >> str){
          vector<long long> ch(256, 0);
          string a;
          for (int i = 0; i < str.size(); i++)
          {
              if (ch[str[i]] == 0)
              {
                   a += str[i];
              }
              ch[str[i]]++;
          }
          int m = a.size() - 1
          for (int i = 0; i < a.size(); i++)
          {
              cout << a[i] << ":" << ch[a[i]];
              if (m)
              {
                   cout << ",";
                   m--;
              }
          }
     }
     return 0;
}