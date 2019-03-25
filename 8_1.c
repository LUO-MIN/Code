//运用可变参数求平均值

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
int average(int n, ...)//...可变参数
{
	va_list arg;
	int sum = 0;
	int i = 0;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);
	}
	va_end(arg);
	return sum / n;

}
int main()
{
	int ret = average(4, 2, 4, 6, 8);
	printf("%d\n", ret);
	ret = average(5, 5, 10, 20, 40, 30);
	printf("%d\n", ret);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
int Max(int n, ...)//...可变参数
{
	va_list arg;
	int max = 0;
	int i = 0;
	int k = 0;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		k = va_arg(arg, int);
		if (max<k)
		{
			max = k;
		}
		
	}
	va_end(arg);
	return max;
}
int main()
{
	int ret = Max(4, 2, 4, 6, 8);
	printf("%d\n", ret);
	return 0;
}

