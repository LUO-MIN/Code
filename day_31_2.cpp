//因式分解
//用开方的方式，提高效率
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//	unsigned int a;
//
//	while (cin >> a){
//		cout << a<<' ' << "=" << ' ';
//		for (size_t i = 2; i <= sqrt(a); i++)
//		{
//			while (a != i && a%i == 0)//
//			{
//				cout << i << ' ' << "*" << ' ';
//				a = a / i;
//			}
//		}
//		cout << a <<endl;
//	}
//}

//美国节日
#include <iostream>
#include <cstdio>
using namespace std;

int day_of_week(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}
	int century = year / 100;
	year = year % 100;
	int week = year + (year / 4) + (century / 4) - 2 * century + 26 * (month + 1) / 10 + day - 1;
	week = (week % 7 + 7) % 7;

	if (week == 0){
		week = 7;
	}
	return week;
}

int day_of_demand(int year, int month, int count, int d_of_week)
{
	int week = day_of_week(year, month, 1);
	int day = 1 + (count - 1) * 7 + ((7 - week) + d_of_week) % 7;
	return day;
}
//元旦
void new_year_day(int year)
{
	printf("%d-01-01\n", year);
}
//马丁.路德金纪念日
void martain_day(int year)
{
	printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
}
//总统日
void president_day(int year)
{
	printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
}
//阵亡将士纪念日
void memorial_day(int year)
{
	int week = day_of_week(year, 6, 1);
	int day = 31 - ((week == 1) ? 6 : (week - 2));
	printf("%d-05-%02d\n", year, day);
}
//国庆
void independence_day(int year)
{
	printf("%d-07-04\n", year);
}
//劳动节
void lador_day(int year)
{
	printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
}
//感恩节
void thanks_day(int year)
{
	printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
}
//圣诞节
void christmas(int year)
{
	printf("%d-12-25\n", year);
}
//美国节日
void holiday_of_usa(int year)
{
	new_year_day(year);
	martain_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	lador_day(year);
	thanks_day(year);
	christmas(year);
}

int main()
{
	int year;
	while (std::cin >> year){
		holiday_of_usa(year);
		printf("\n");
	}
}