//使用main函数的参数，实现一个整数计算器，程序可以接受三个参数，第一个参数“-a”选项执行加法，“-s”选项执行减法，“-m”选项执行乘法，“-d”选项执行除法，后面两个参数为操作数。

//例如：命令行参数输入：test.exe - a 1 2
//执行1 + 2输出3
#include <stdio.h>
int Div(int x, int y)
{
	return x / y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Add(int x, int y)
{
	return x + y;
}
int main(int argc,char *argv[],char *envp[])
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
	printf("ret = %d\n", ret);
	return 0;
}


//写冒泡排序可以排序多个字符串。
#include <stdio.h>
#include <string.h>
void arr_bubble_sort(char(*p)[10])//数组指针，即指向大小为10的数组的指针
{
	int i = 0;
	int j = 0;
	char temp[10];
	char *t = temp;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5 - i - 1; j++)
		{
			if (strcmp(p[j], p[j + 1])>0)
			{
				strcpy(t, p[j]);
				strcpy(p[j], p[j + 1]);
				strcpy(p[j + 1], t);
			}
		}
	}
}
int main()
{
	char a[5][10] = { "abc", "bcd", "sfg","fghj","nikl" };
	char i = 0;
	char(*p)[10] = { 0 };
	p = a;//p指向a的第0行
	arr_bubble_sort(p);
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", a[i]);//按行输出
	}
	system("pause");
	return 0;
}












