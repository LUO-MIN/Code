//编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回 值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
#include<stdio.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int ret = 0;
	int tmp = 0;
	for (i = 0; i < 32; i++)
	{
		ret = ret << 1;
		tmp = value & 1;//判断最后一位是0还是1
		value = value >> 1;
		ret = ret | tmp;
	}
	return ret;

}
int main()
{
	int num = 0;
	printf("输入一个数：");
	scanf("%d", &num);
	printf("反转后的值:%u\n",reverse_bit(num));
	return 0;
}

//不使用（a + b） / 2这种方式，求两个数的平均值。
#include <stdio.h>
int main()
{
	int arr[9] = { 2, 3, 4, 5, 6, 5, 4, 3, 2 };
	int i = 0;
	int tmp = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < size; i++)
	{
		tmp = tmp^arr[i];
	}
	printf("未成对的数字是%d\n", tmp);
}

//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
#include<stdio.h>
#include<string.h>

int main()

{

	char arr1[10][20];
	char arr2[20];
	int i = 0;
	int j = 0;
	int  p= 0;
	int q = 0;
	int n = 0;
	printf("please input a string:\n");
	gets_s(arr2, 100);
	for (i = 0; arr2[i] != '\0'; i++)
	{
		n++;
	}
	for (i = 0; arr2[i] != '\0'; i++)
	{
		if (arr2[i] != ' ')
		{
			arr1[p][q] = arr2[i];
			q++;
		}
		else
		{
			arr1[p][q] = '\0';
			p++;
			q = 0;

		}
		if (i == n - 1)
		{
			arr1[p][q] = '\0';
			p++;
		}
	}
	arr1[p][0] = '\0';
	for (i = p - 1; i >= 0; i--)
	{
		printf("%s ", arr1[i]);
	}
	printf("\n");
	return 0;

}