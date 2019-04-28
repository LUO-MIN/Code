////二进制插入
//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i) {
//		m = (m << j);
//		return n | m;
//	}
//};


//最大公共字符串长度计算
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int max = 0;
	string str1, str2;
	while (cin >> str1 >> str2){
		int len1 = str1.size();
		int len2 = str2.size();
		
		//定义一个二位数组，将二维数组中的值都初始化为0
		vector<vector<int>> dp(len1, vector<int>(len2, 0));
		//遍历两个字符串
		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (str1[i] == str2[j])
				{
					if (i >= 1 && j >= 1)
						dp[i][j] = dp[i - 1][j - 1] + 1;
			
					else
						dp[i][j] = 1;

				}
				if (dp[i][j] > max)
				{
					max = dp[i][j];
				}	
			}
		}
		cout << max << endl;
	}
	return 0;
}
