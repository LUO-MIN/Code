#include<iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long a = 1;
	long long b = 1;
	long long c = 0;

	if (n <= 2)
	{
		cout << a << endl;
	}
	else{
		n = n - 2;
		while (n){
			c = a + b;
			a = b;
			b = c;
			n--;
		}
		cout << c << endl;
	}

	return 0;
}