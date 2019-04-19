////����С������
////��С������=����֮���������Լ��
////���Լ������շת����� 
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int r;
	while (r = a%b){
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b){
		cout<<a*b/gcd(a, b)<<endl;
	}
}

//��������
// 1.�����ַ������ֵ����������磺
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.�����ַ����ĳ����������磺
//"car" < "cats" < "koala" < "doggies" < "carriage"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[100][100];
int Lengths(int n)
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		//����strlen����0�ͽ���������,ÿһ���ַ������бȽ�
		if (strlen(str[i])<strlen(str[i - 1]))
		{
			return -1;
		}
	}
	return 0;
}
int checkLexicograph(int n)
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		if (strcmp(str[i - 1], str[i])>0)
		{
			return -1;
		}
	}
	return 0;
}

int main()
{
	int n;
	int i;
	int Len, Lex;

	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%s", str[i]);//һ���ַ�����ʼ��һ��
	}
	Len = Lengths(n);
	Lex = checkLexicograph(n);
	if (Len != 0 && Lex != 0)
	{
		printf("none\n");
	}
	if (Len != 0 && Lex == 0)
	{
		printf("lexicographically\n");
	}
	if (Len == 0 && Lex != 0)
	{
		printf("lengths\n");
	}
	if (Len == 0 && Lex == 0)
	{
		printf("both\n");
	}

}