
//������
//���磬����24 ��˵����2 ��4 ��ӵõ�6������6 ��һλ�������6 ��24 ��������
//�ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 �����������õ�3������һ��һλ�������3 ��39 ��������
//ÿ���������ݰ���һ��������n��1��n��10E1000��ע��������������ͳ������κ����͵ķ�Χ��ֻ�����ַ������洢����
//#include <iostream>
//#include <string> 
//using namespace std;
//int numroot(int n)
//{
//	int root = 0;
//	while (n){
//		root += n % 10;
//		n = n / 10;
//	}
//	while (root>9){
//		root = numroot(root); //�������õݹ�
//	}
//	return root;
//}
//
//int main()
//{
//	string n;
//	while (cin >> n){
//		int sum = 0;
//		for (int i = 0; i < n.length(); i++)
//		{
//			sum += n[i] - '0';//ת��������  �ַ����ֿ���ͨ��ASCII��ת�����߼����֣�
//		}
//
//
//		cout << numroot(sum) << endl;
//	}
//	return 0;
//}


//�Ǽ�����
#include <stdio.h>

int a[10005] = { 0, 1, 2, 3, 5 };
void data_init()
{
	int i;
	for (i = 3; i < 10005; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		if (a[i] >= 10000)
			a[i] %= 10000;
	}
}
int main()
{
	int n, t;
	data_init();
	while (scanf("%d", &n) != EOF)
	{
		while (n--)
		{
			scanf("%d", &t);
			printf("%04d", a[t]);
		}
		printf("\n");
	}
	return 0;
}
