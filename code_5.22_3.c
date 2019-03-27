//输出1000-2000的闰年
#include<stdio.h>
int main()
{
	int year;
	for (year = 1000; year <= 2000; year++)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			printf("%d年是闰年。", year);
		}
	}
	return 0;
}