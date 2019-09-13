#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	string str;
	cin >> str;
	vector<int> ch(256, 0);
	string a;
	for (int i = 0; i<str.length(); i++)
	{
		if (ch[str[i]] == 1)
		{
			a += str[i];
		}
		if (str[i + 1] == str[i] || str[i - 1] == str[i])
			ch[str[i]]++;
	}

	for (int i = 0; i < a.size(); i++)
	{
		for (int i = 0; i<a.size() - 1; i++)
		{
			if (ch[a[i]] < ch[a[i + 1]])
			{
				swap(a[i], a[i + 1]);
			}
		}
	}
	if (a.empty())
	{
		cout << "0" << endl;
		return 0;
	}
	for (int i = 0; i<a.size(); i++)
	{
		if (ch[a[i]]>1)
		{
			cout << a[i] << ":" << ch[a[i]] << endl;
		}
		else{
			continue;
		}
		
	}
	return 0;
}