//ʹ��main�����Ĳ�����ʵ��һ��������������������Խ���������������һ��������-a��ѡ��ִ�мӷ�����-s��ѡ��ִ�м�������-m��ѡ��ִ�г˷�����-d��ѡ��ִ�г�����������������Ϊ��������

//���磺�����в������룺test.exe - a 1 2
//ִ��1 + 2���3
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
		printf("������������argc=%d\n", argc);
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


//дð����������������ַ�����
#include <stdio.h>
#include <string.h>
void arr_bubble_sort(char(*p)[10])//����ָ�룬��ָ���СΪ10�������ָ��
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
	p = a;//pָ��a�ĵ�0��
	arr_bubble_sort(p);
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", a[i]);//�������
	}
	system("pause");
	return 0;
}












