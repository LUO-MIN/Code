//求斐波那契数的非递归方法
#include <stdio.h>
int main()
{
	int a = 1; 
	int b = 1;
	int c = a;
	int n = 6;
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		while (n > 2)
		{
			c = a + b;
			a = b;
		    b = c;
			n--;
		}
	}
	printf("第n个斐波那契数是：%d\n",c);
	return 0;
}

//用递归的方法计算斐波那契数
#include <stdio.h>
int fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fib(n-2)+fib(n-1);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);

	printf("%d", fib(n));
	return 0;
}

//编写一个函数实现n^k，使用递归实现
#include <stdio.h>
int power(int n,int k)
{
	if (k <= 0)
	{
		return 1;
	}
	else if (k == 1)
	{
		return n;
	}
	else
	{
		return n*power(n,k-1);
	}
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	
	int ret = power(n,k);
	printf("%d的%d次方是：%d\n", n, k, ret);
	return 0;
}

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19 
#include <stdio.h>

int DigitSum(int num)
{
	if (num > 9)
	{
		return num % 10 + DigitSum(num / 10);
	}
	return num;
}
int main()
{
	
	int num = 0;
	scanf("%d", &num);
	int sum = DigitSum(num);
	printf("sum = %d",sum );

	return 0;
}

//4. 编写一个函数reverse_string(char * string)（递归实现） 
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
#include <stdio.h>
#include <assert.h>

int reverse_string(const char* str)
{
	if (*str == '\0')
	{
		printf("%c", *str);
	}
	else
	{
		reverse_string(++str);
		printf("%c\n", *(--str));
	}
}
int main()
{
	char *p = "abcde";
	
	reverse_string(p);
	
	return 0;	 
}
//5.递归和非递归分别实现strlen
//递归
#include <stdio.h>
#include <assert.h>
int my_strlen(const char* str)
{
	assert(str != NULL);

	if (*str != '\0')
	{
		return 1 + my_strlen(str + 1);
	}
	else
	{
		return 0;
	}

}
int main()
{
	char *p = "abcdef";
	int len = my_strlen(p);
	printf("len = %d\n", len);
	return 0;
}
//非递归
#include <stdio.h>
#include <assert.h>
int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;

}
int main()
{
	char *p = "abcdefg";
	int len = 0;
	len = my_strlen(p);
	printf("%d\n", len);

}
//6.递归和非递归分别实现求n的阶乘
#include <stdio.h>
int fac(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 0)
	{
		return 0;
	}
	else 
	{
		return n*fac(n - 1);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = 0;
	ret = fac(n);
	printf("%d的阶乘是：%d\n",n, ret);
}
//7.递归方式实现打印一个整数的每一位
#include <stdio.h>
void  print(int num)
{
	if (num > 9)
	{
		 print(num / 10);
	}
	printf("%d ", num % 10);
}
int main()
{
	int num = 0;
	scanf("%d", &num);

	print(num);
	return 0;
}




