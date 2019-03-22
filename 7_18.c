//写一个宏可以将一个数字的奇数位和偶数位交换。
#include <stdio.h>
#define EXCHANGE(X) ((X&(0xAAAAAAAAA)>>1)+(X&(0X555555555))) 
//将X转化为二进制，而0xAAAAAAAAA的偶数位都为1-->1010 1010 1010 1010 1010 1010 1010 1010与X与之后X的所有奇数位都变为零，偶数位不变，再将位数向右移动一位，偶数位即变成奇数位。0x555555555的奇数位都为1-->0101 0101 0101 0101 0101 0101 0101 0101  与X与后奇数位不变，偶数位全为零，在将所有奇数位向左移动一位，奇数位全变为偶数位。
int main()
{
	int num = 0;
	int i = 0;
	int ret = 0;
	printf("输入一个数：");
	scanf("%d", &num);
	printf("该数字的二进制序列是：\n");
	for (i = 31; i >= 0; i--)
	{
		printf("%d", (num >> i) & 1);
	}
	ret = EXCHANGE(num);
	printf("\n交换数位后的序列：\n");
	for (i = 31; i >= 0; i--)
	{
		printf("%d", (ret >> i) & 1);
	}
	printf("\n");
	return 0;
}

//使用宏实现两个数中求较大值
#include <stdio.h>
#define MAX(X,Y) (X)>(Y)?(X):(Y)
int main()
{
	int a = 80;
	int b = 19;
	int ret = 0;
	ret = MAX(a, b);
	printf("%d\n", ret);
}