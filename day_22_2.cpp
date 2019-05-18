//查找字符串中只出现一次的字符
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (cin >> str){
		int hashtable[256] = { 0 };
		for (auto& e : str)
		{
			hashtable[e]++;
		}
		int i;
		for (i = 0; i<str.size(); i++)
		{
			if (hashtable[str[i]] == 1)
			{
				cout << str[i] << endl;
				break;
			}
		}
		if (i >= str.size())
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
//打怪加能量
#include <iostream>
#include <vector>
using namespace std;
int gcd(int x, int y)
{
	int r = 0;
	while (r = x%y){
		x = y;
		y = r;
	}
	return y;
}
int main()
{
	int n, c;
	vector<int> v(n);
	v.resize(100000);
	while (cin >> n >> c){
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i<n; i++)
		{
			if (v[i] <= c)
			{
				c = c + v[i];
			}
			else
			{
				c += gcd(c, v[i]);
			}
		}
		cout << c << endl;
	}
}