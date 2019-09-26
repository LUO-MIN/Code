#include <iostream>
#include <algorithm>
using namespace std;

bool Prime(int x)
{
	for (int i = 2; i < x; i++)
	{
		if (x%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;

	int ret1,ret2,res1,res2;
	for (int i = n; i > 0; i--)
	{
		if (Prime(i))
		{
			ret1 = n - i;
			res1 = i;
			break;
		}
	}
	for (int i = n; i < 10000; i++)
	{
		if (Prime(i))
		{
			ret2 = i - n;
			res2 = i;
			break;
		}
	}
	if (ret1 <= ret2)
	{
		cout << res1 << endl;
	}
	else{
		cout << res2 << endl;
	}
	return 0;
}