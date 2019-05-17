

//打怪加能量
#include <iostream>
#include <vector>
using namespace std;
int gcd(int x, int y)
{
	int r = 0;
	while (r = x%y){
		x = y;
		y = r;
	}
	return y;
}
int main()
{
	int n, c;
	vector<int> v(n);
	v.resize(100000);
	while (cin >> n >> c){
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i<n; i++)
		{
			if (v[i] <= c)
			{
				c = c + v[i];
			}
			else
			{
				c += gcd(c, v[i]);
			}
		}
		cout << c << endl;
	}
}