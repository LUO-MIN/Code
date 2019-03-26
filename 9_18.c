//可变参数求均值
#include <stdio.h>
int main(int argc, char* argv[], char* envp[])
{
	int i = 0;
	for (i = 0; i<argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return 0;
}
#include <stdio.h>
int main(int argc, char* argv, char* envp[])
{
	int i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return 0;
}

#include <stdio.h>
#include <stdarg.h>

int average(int n, ...)  // n表示参数个数
{
	va_list arg;
	int i = 0;
	int sum = 0;
	va_start(arg, n);
	for (i = 0; i<n; i++)
	{
		sum += va_arg(arg, int);
	}
	return sum / n;
	va_end(arg);
}
int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int avg1 = average(2, a, c);
	int avg2 = average(3, a, b, c);
	printf("avg1 = %d\n", avg1);
	printf("avg2 = %d\n", avg2);
	return 0;
}

//计算器
#include <stdio.h>
#include <stdlib.h>

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x*y;
}
int Div(int x, int y)
{
	return x / y;
}

int main(int argc, char* argv[], char* envp[])
{
	int ret = 0;
	if (argc != 4)
	{
		printf("参数个数有误：argc=%d\n", argc);
		return 0;
	}
	switch (*(argv[1] + 1))
	{
	case 'a':
		ret = Add(atoi(argv[2]), atoi(argv[3]));
		break;
	case 's':
		ret = Sub(atoi(argv[2]), atoi(argv[3]));
		break;
	case 'm':
		ret = Mul(atoi(argv[2]), atoi(argv[3]));
		break;
	case 'd':
		ret = Div(atoi(argv[2]), atoi(argv[3]));
		break;
	}
	printf("ret = %d\n",ret);
	return 0;
}























