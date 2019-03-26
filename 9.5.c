
#include <stdio.h>

static int j;

void fun1()
{
	static int i = 0;
	i++;
}

void fun2()
{
	j = 0;
	j++;
}
int main()
{
	int k = 0;
	for (k = 0; k < 10; k++)
	{
		fun1();
		fun2();
	}
	
	return 0;
}

//200以内的素数
#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 100; i < 200; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j == i)
		{
			printf("%d是素数\n", i);
			
		}
		count++;
		printf("\n%4d", count);
		system("pause");
	}
	return 0;
}

