//不要二  W*H的网格中，任意两个格子的坐标的欧几里得距离不等于2
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int w, h;
	int res = 0;
	cin >> w >> h;
	vector<vector<int> > a;
	a.resize(w);
	for (auto& e : a)
		e.resize(h, 1);

	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j<h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				if ((i + 2)<w)
				{
					a[i + 2][j] = 0;
				}
				if ((j + 2)<h)
				{
					a[i][j + 2] = 0;
				}
			}
		}
		cout<<res;
		return 0;
	}
}


 