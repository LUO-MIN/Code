////求最小公倍数
////最小公倍数=两数之积除以最大公约数
////最大公约数：用辗转相除法 
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

//两种排序
// 1.根据字符串的字典序排序。例如：
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.根据字符串的长度排序。例如：
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
		//利用strlen遇到0就结束的性质,每一行字符串进行比较
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
		scanf("%s", str[i]);//一个字符串初始化一行
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