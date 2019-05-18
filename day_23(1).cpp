//微信红包
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		int mid = gifts[n / 2];
		int count = 0;

		for (int i = 1; i<n; i++)
		{
			if (mid == gifts[i])
			{
				count++;
			}
		}
		if (count>n / 2)
		{
			return mid;
		}
		else
			return 0;

	}
};


//计算两个字符串的距离
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int minDistance(string word1, string word2)
{
	if (word1.empty() || word2.empty())
	{
		return max(word1.size(), word2.size());
	}
	int len1 = word1.size();
	int len2 = word2.size();

	vector<vector<int> > f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i){
		f[i][0] = i;
	}
	for (int i = 0; i <= len2; i++)
	{
		f[0][i] = i;
	}
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			if (word1[i - 1] == word2[j - 1]){
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
			else
			{
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);

			}
		}
	}
	return f[len1][len2];
}
int main()
{
	//动态规划
	string a, b;
	while (cin >> a >> b)
	{
		cout << minDistance(a, b) << endl;
	}
	return 0;
}