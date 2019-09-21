//数组a[100],是1-100的乱序排列，将一个元素替换为-1，找到这个数的下标，和改变哪个数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> a;
	int cur = 0;
	int res = 0;
	int tmp;
	while (cin >> tmp)
	{
		a.push_back(tmp);
		if (getchar() == '\n')
			break;
	}

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == -1)
		{
			cur = i;
			break;
		}
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] != i)
		{
			res = i;
			break;
		}
	}
	cout << cur << endl;
	cout << res << endl;
	return 0;
}