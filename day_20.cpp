//翻转一个字符串
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	getline(cin, s);

	reverse(s.begin(), s.end());

	cout << s << endl;
}

//输入一个偶数，输出两个素数相加等于它，且这两个素数差值最小
#include <iostream>
#include <cmath>
using namespace std;
bool IsPrime(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int num;
	int half;
	int i;
	while (cin >> num)
	{
		half = num / 2;
		for (i = half; i>0; i--)
		{
			if (IsPrime(i) && IsPrime(num - i))
			{
				break;
			}
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}