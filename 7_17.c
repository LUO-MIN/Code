//��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ��� ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
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
		tmp = value & 1;//�ж����һλ��0����1
		value = value >> 1;
		ret = ret | tmp;
	}
	return ret;

}
int main()
{
	int num = 0;
	printf("����һ������");
	scanf("%d", &num);
	printf("��ת���ֵ:%u\n",reverse_bit(num));
	return 0;
}

//��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
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
	printf("δ�ɶԵ�������%d\n", tmp);
}

//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
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