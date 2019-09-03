#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

	vector<int> nums;
	int tmp;
	while (cin >> tmp)
	{
		nums.push_back(tmp);
		if (getchar() == '\n')
		{
			break;
		}
	}

	sort(nums.begin(), nums.end());
	int res = 0;
	int sum = 0;
	int count = 0;
	for (size_t i = 1; i < nums.size(); i++)
	{
		res = nums[i];
		for (size_t j = i - 1; j >= 0; j--)
		{
			sum = res + nums[j];
			if (sum == 0)
			{
				count++;
				break;
			}
			sum = 0;
		}
	}
	cout << count << endl;
	return 0;
}