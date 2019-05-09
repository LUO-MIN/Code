//兔子问题
/*
f1=1   f2=1  f3=2  f4=3  f5=5
fn=f(n-1)+f(n-2)
*/
#include <iostream>
using namespace std;
int fib(int n)
{
	if (n<3)
	{
		return 1;
	}
	else{
		return fib(n - 1) + fib(n - 2);
	}
}
int main()
{
	int mouth;
	while (cin >> mouth){
		cout << fib(mouth) << endl;
	}
}
//非递归
#include <iostream>
using namespace std;
int fib(int n)
{
	int a = 1, b = 1, c = 0;

	if (n <= 2)
	{
		return a;
	}
	else{
		while (n>2){
			c = a + b;
			a = b;
			b = c;
			n--;
		}
		return c;
	}
}
int main()
{
	int mouth;
	while (cin >> mouth){
		cout << fib(mouth) << endl;
	}
}

//字符串通配符
#include <iostream>
#include <string>
using namespace std;
//将字符串转化成字符一一比较
bool Match(const char* s, const char* t)
{
	if (*s == '\0' && *t == '\0')
	{
		return true;
	}
	if (*s == '\0' || *t == '\0')
	{
		return false;
	}
	else if (*s == '?')
	{
		return Match(s + 1, t + 1);
	}
	else if (*s == '*')
	{
		return Match(s + 1, t) || Match(s + 1, t + 1) || Match(s, t + 1);
	}
	else if (*s == *t)
	{
		return Match(s + 1, t + 1);
	}
	return false;
}

int main()
{
	string s;
	string t;
	while (cin >> s >> t){
		bool ret = Match(s.c_str(), t.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}