//дһ������Խ�һ�����ֵ�����λ��ż��λ������
#include <stdio.h>
#define EXCHANGE(X) ((X&(0xAAAAAAAAA)>>1)+(X&(0X555555555))) 
//��Xת��Ϊ�����ƣ���0xAAAAAAAAA��ż��λ��Ϊ1-->1010 1010 1010 1010 1010 1010 1010 1010��X��֮��X����������λ����Ϊ�㣬ż��λ���䣬�ٽ�λ�������ƶ�һλ��ż��λ���������λ��0x555555555������λ��Ϊ1-->0101 0101 0101 0101 0101 0101 0101 0101  ��X�������λ���䣬ż��λȫΪ�㣬�ڽ���������λ�����ƶ�һλ������λȫ��Ϊż��λ��
int main()
{
	int num = 0;
	int i = 0;
	int ret = 0;
	printf("����һ������");
	scanf("%d", &num);
	printf("�����ֵĶ����������ǣ�\n");
	for (i = 31; i >= 0; i--)
	{
		printf("%d", (num >> i) & 1);
	}
	ret = EXCHANGE(num);
	printf("\n������λ������У�\n");
	for (i = 31; i >= 0; i--)
	{
		printf("%d", (ret >> i) & 1);
	}
	printf("\n");
	return 0;
}

//ʹ�ú�ʵ������������ϴ�ֵ
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