#include<stdio.h>
int main()
{
	int ch;
	int count = 0;
	while ((ch = getchar()) != EOF) //�ж�ch�Ƿ����-1
	{
		if (ch == '{')
		{
			count++;

		}
		if (ch == '}' && count == 0)
		{
			printf("��ƥ��\n");
			return 0;
		}
		if (ch == '}' && count != 0)
		{
			count--;

		}
	}

	if (count == 0)
	{
		printf("ƥ��\n");

	}
	else
	{
		printf("��ƥ��\n");
	}

	return 0;
}
