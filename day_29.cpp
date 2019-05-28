/*给定一个全是正数的数组arr，定义一下arr的最小不可组成和的概念： 1，arr的所有非空子集中，把每个子集内的所有元素加起来会出现很多的值，其中最小的记为min，最大的记为max； 2，在区间[min, max]上，如果有一些正数不可以被arr某一个子集相加得到，那么这些正数中最小的那个，就是arr的最小不可组成和； 3，在区间[min, max]上，如果所有的数都可以被arr的某一个子集相加得到，那么max + 1是arr的最小不可组成和； 举例： arr = { 3, 2, 5 } arr的min为2，max为10，在区间[2, 10]上，4是不能被任何一个子集相加得到的值中最小的，所以4是arr的最小不可组成和； arr = { 3, 2, 4 } arr的min为2，max为9，在区间[2, 9]上，8是不能被任何一个子集相加得到的值中最小的，所以8是arr的最小不可组成和； arr = { 3, 1, 2 } arr的min为1，max为6，在区间[2, 6]上，任何数都可以被某一个子集相加得到，所以7是arr的最小不可组成和； 请写函数返回arr的最小不可组成和。 */
//   01背包问题

class Solution {
public:
	/**
	*	正数数组中的最小不可组成和
	*	输入：正数数组arr
	*	返回：正数数组中的最小不可组成和
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) {
		int sum = 0, min = arr[0];
		int i, j;
		for (int i = 0; i<len; i++)
		{
			sum += arr[i];
			min = arr[i]<min ? arr[i] : min;
		}
		std::vector<int> dp(sum + 1, 0);
		for (i = 0; i<len; i++)
		{
			for (j = sum; j >= arr[i]; j--)
			{
				if (dp[j]<dp[j - arr[i]] + arr[i])
					dp[j] = dp[j - arr[i]] + arr[i];
				else
					dp[j] = dp[j];
			}
		}
		for (i = min; i <= sum; i++)
		{
			if (i != dp[i])
				return i;
		}
		return sum + 1;
	}
};


//找假币
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	long long n;
	int count;
	while ((scanf("%lld", &n)) != EOF){
		if (n == 0)
			break;
		count = 0;
		while (n >= 2){
			if (n % 3)
			{
				n = n / 3 + 1;
			}
			else{
				n = n / 3;
			}
			count++;
		}
		printf("%d\n", count);
	}
	return 0;
}