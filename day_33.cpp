//斐波那契数列n项到m项求和
//误区：数据类型不够大，装太大的数，还是需要数组解决
#include <iostream>
using namespace std;

int fib(int x)
{
	long long a, b, c;
	a = b = 1;
	c = a;
	if (x <= 2)
	{
		c = a;
	}
	else{
		while (x >  2){
			c = a + b;
			a = b;
			b = c;
			x--;
		}
	}
	return c;
}

int main()
{
	long long n, m;
	while (cin >> n >> m){
		long long sum = 0;
		while (n <= m){
			sum += fib(n);
			n++;
		}
		cout << sum << endl;
	}
}

