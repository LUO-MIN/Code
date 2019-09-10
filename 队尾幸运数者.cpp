/*
N个人排成一个队列，从1到5循环报数，当报到5的是幸运者，出列
接着继续报数，直到队尾的人变成幸运者，请问队尾的幸运者是第几个幸运者
测试用例:
1  1
2  2
3  3
5  1
8  3 
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	cin >> num;
	vector<int> v(num+1, 1);
	int count = 0;
	int res = 0;
	while (1)
	{
		for (int i = 1; i <= num; i++)
		{ 
			if (v[i] != 0)
			{
				count++;
			}
			if (count % 5 == 0)
			{
				v[i] = 0;
				res++;
			}
			if (count % 5 == 0 && v[num] == 0)
			{
				cout << res << endl;
				return 0;
			}
			
		}
	}
	
}
