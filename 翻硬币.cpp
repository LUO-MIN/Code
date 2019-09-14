/*
桌子上放着N枚硬币，将其从1到N编号，初始时有的正面朝上，有的反面朝上。现在要将所有硬币翻至正面朝上，每次可以选择一个区间[L，R]（1≤L≤R≤N），并执行以下两种操作中的一种：
①将编号为L到R的硬币翻面；
②若编号为L到R的硬币均反面朝上，则将其翻至正面朝上。
其中操作①所需的代价为x，操作②所需的代价为y，那么将所有硬币翻至正面朝上所需的总代价最小是多少？
输入
第一行包含三个整数N、x和y，1≤N≤105，1≤x，y≤10。
第二行包含N个空格隔开的整数t1到tN，0≤ti≤1。若ti = 0，则表示i号硬币初始时反面朝上；若ti = 1，则表示i号硬币初始时正面朝上。
输出
输出总代价的最小值。
样例输入
3 1 2
0 1 0
样例输出
2
提示
第一次选择区间[1，3]并执行操作①，第二次选择区间[2，2]并同样执行操作①。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int MinEngery(vector<int> &t, int n, int x, int y)
{
	int engry = 0;
	for (int i = 0; i<n; i++)
	{
		int end = i;
		if (t[i] == 0)
		{
			while (end<n && t[end] == 0)
			{
				end++;
			}
			engry += min(x, y);
		}
		i = end;
	}
	return engry;
}

int main()
{
	int n;
	int x, y;
	cin >> n;
	cin >> x >> y;
	vector<int> t(n);
	for (int i = 0; i<n; i++)
	{
		cin >> t[i];
	}
	int ret = MinEngery(t, n, x, y);
	cout << ret << endl;
	return 0;

}
