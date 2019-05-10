//汽水瓶问题
//注意巧用循环
#include <iostream>
using namespace std;
int Sum(int n)
{
	int sum = 0;
	while (n>1)//关于为什么要大于1，因为等于2时，可以借一个空瓶，喝完再还
	{
		int result = n / 3;
		int tmp = n % 3;//不足三瓶先保留
		sum += result;
		n = result + tmp;//*喝完兑换来的汽水还可以得到空瓶
		if (n == 2)
		{
			sum++;
			break;
		}
		//n等于1瓶时，不满足条件跳出循环，
		//走到这里说明n大于2，还可以兑换,重复之前的做法！！！切记
	}
	return sum;
}
int main()
{
	int n;
	while (cin >> n){
		cout << Sum(n) << endl;
	}
	return 0;
}

//两个字符串的最长公共子串
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b){

		if (a.size() > b.size())
		{
			swap(a, b);
		}

		int len1 = a.size(), len2 = b.size();
		int i, j, start = 0, max = 0;

		vector<vector<int> > MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		{
			for (j = 1; j <= len2; j++)
			{
				if (a[i - 1] == b[j - 1])
				{
					MCS[i][j] = MCS[i - 1][j - 1] + 1;
				}
				if (MCS[i][j]>max)
				{
					max = MCS[i][j];
					start = i - max;
				}
			}
		}
		cout << a.substr(start, max) << endl;
	}
	return 0;
}
