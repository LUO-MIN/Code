//求最小公倍数
//最小公倍数=两数之积除以最大公约数
//最大公约数：用辗转相除法 
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