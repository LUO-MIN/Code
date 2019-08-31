//寻找一个字符串中的所有子串中出现次数最多的子串
//实际找出现最多的字符
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	string str;
	cin >> str;
	
	vector<int> ch(256, 0);
	string a;
	for (int i = 0; i < str.size(); i++)
	{
		if (ch[str[i]] == 0)
		{
			a += str[i];
		}
		ch[str[i]]++;
	}
	int count = 0;
	int maxcount = 0;
	for (int i = 0; i < a.size(); i++)
	{
		count = ch[a[i]];
		maxcount = max(count, maxcount);
	}
	cout << maxcount << endl;
	return 0;
}
