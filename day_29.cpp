/*����һ��ȫ������������arr������һ��arr����С������ɺ͵ĸ�� 1��arr�����зǿ��Ӽ��У���ÿ���Ӽ��ڵ�����Ԫ�ؼ���������ֺܶ��ֵ��������С�ļ�Ϊmin�����ļ�Ϊmax�� 2��������[min, max]�ϣ������һЩ���������Ա�arrĳһ���Ӽ���ӵõ�����ô��Щ��������С���Ǹ�������arr����С������ɺͣ� 3��������[min, max]�ϣ�������е��������Ա�arr��ĳһ���Ӽ���ӵõ�����ômax + 1��arr����С������ɺͣ� ������ arr = { 3, 2, 5 } arr��minΪ2��maxΪ10��������[2, 10]�ϣ�4�ǲ��ܱ��κ�һ���Ӽ���ӵõ���ֵ����С�ģ�����4��arr����С������ɺͣ� arr = { 3, 2, 4 } arr��minΪ2��maxΪ9��������[2, 9]�ϣ�8�ǲ��ܱ��κ�һ���Ӽ���ӵõ���ֵ����С�ģ�����8��arr����С������ɺͣ� arr = { 3, 1, 2 } arr��minΪ1��maxΪ6��������[2, 6]�ϣ��κ��������Ա�ĳһ���Ӽ���ӵõ�������7��arr����С������ɺͣ� ��д��������arr����С������ɺ͡� */
//   01��������

class Solution {
public:
	/**
	*	���������е���С������ɺ�
	*	���룺��������arr
	*	���أ����������е���С������ɺ�
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


//�Ҽٱ�
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