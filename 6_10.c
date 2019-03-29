#include <stdio.h>
void print(num)
{
	if (num > 9)
	{
		printf(num / 10);
	}
	printf("%d", num % 10);
}

int main() 
{
	int num = 0;
	int m = 0;
	printf("请输入一个数\n");   
	scanf("%d", &num);
	print(num);
	return 0; 
} 