//����һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int arr[], int a, int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;

}
void change_arr(int arr[],int sz)
{
	int i = 0;
	int j = sz-1;
	int tmp = 0;
	while (i < j)
	{
		while ((i < j) && (arr[i] % 2 == 1))
		{
			i++;
		}
		while ((i < j) && (arr[j] % 2 == 0))
		{
			j--;
		}
		if (i != j)
		{
			swap(arr, i, j);
		}
	}
}

int main()
{
	int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	for (i = 0; i < sz; i++)
	{
		change_arr(arr, sz);
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

//���Ͼ���
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
#include <stdio.h>
#define N 3
int find(int a[][N],int key)
{
	int i = 0;
	int j = N-1;
	
	while (i<N&&j>=0)
	{
			if (a[i][j]==key)
			{
				return 1;
			}
			else if (a[i][j] < key)
			{
				i++;
			}
			else if (a[i][j]>key)
			{
				j--;
			}
		}
	return 0;
	}

int main()
{
	int a[N][N] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	int i = 0;
	int j = 0;
	int num = 0;
	printf("����һ�����֣�");
	scanf("%d", &num);
	int ret=find(a,num);
	if (ret==1)
	{
		printf("�ҵ�������\n");

	}
	else
	{
		printf("�����ڸ�����\n");
	}
}