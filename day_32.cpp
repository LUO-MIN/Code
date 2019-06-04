//网店盈利
#include <iostream>
using namespace std;

inline int day_of_month(int m){
	const static int day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return day[m];
}

inline int profit_of_year(){
	return 2 * 31
		+ 1 * 28
		+ 1 * 31
		+ 2 * 30
		+ 1 * 31
		+ 2 * 30
		+ 1 * 31
		+ 2 * 31
		+ 2 * 30
		+ 2 * 31
		+ 1 * 30
		+ 2 * 31;

}
//将所有月份都存到数组中，是否是素数，用布尔值来做数组元素
inline bool IsPrime(int n)
{
	const static bool p[] = { false, true, true, false, true, false, true,
		false, false, false, true, false };
	return p[n];
}

//判断是否是闰年
bool IsLeapyear(int n)
{
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
	{
		return true;
	}
	return false;
}
int main()
{
	int year1, month1, day1, year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2){
		int profit = 0;
		int year = year1;

		for (int y = year1; y <= year2 - 1; ++y)
		{
			profit += profit_of_year();
			if (IsLeapyear(y))
			{
				profit += 1;
			}
		}

		for (int m = 0; m<month1; ++m)
		{
			int days;
			if (m == month1 - 1)
			{
				days = day1 - 1;
			}
			else{
				days = day_of_month(m);
				if (m == 1 && IsLeapyear(year1))
				{
					days += 1;
				}
			}

			int profit_of_month = days*(IsPrime(m) ? 1 : 2);
			profit -= profit_of_month;
		}
		for (int m = 0; m<month2; ++m)
		{
			int days;
			if (m == month2 - 1)
			{
				days = day2;
			}
			else{
				days = day_of_month(m);
				if (m == 1 && IsLeapyear(year2))
				{
					days += 1;
				}
			}

			int profit_of_month = days*(IsPrime(m) ? 1 : 2);
			profit += profit_of_month;
		}
		cout << profit << "\n";

	}
	return 0;

}




//求一个大斐波那契数
#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;

	for (int i = 2; i <= 100000; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000;
	}

	int n;
	while (cin >> n){
		if (n<29){
			printf("%d\n", fib[n]);
		}
		else{
			printf("%06d\n", fib[n]);
		}
	}
	return 0;
}