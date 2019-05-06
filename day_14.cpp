//计算日期到天数的转换
#include <iostream>
using namespace std;
int main()
{
	//将每月累计的天数存入数组
	int array[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

	int year;
	int mouth;
	int day;
	int sum = 0;
	while (cin >> year >> mouth >> day){
		sum = 0;
		sum += array[mouth - 2];//因为当月的天数由day决定
		sum += day;
		if (mouth > 2)//月份大于2，判断时平年还是闰年
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				sum += 1;//闰年比平年多一天
			}
		}
		cout << sum << endl;
	}
}

//幸运袋子，抓小球
//1.将小球的序号，按升序排列
//x[ ]：袋子中所有小球   n:球的总数  pos:当前搜索位置  sum：目前位置的累加和    multi:目前为位置的累积
#include <iostream>
#include <algorithm>

using namespace std;

int getluckpacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	for (int i = pos; i < n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum>multi)
		{
			count += 1 + getluckpacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			count += getluckpacket(x, n, i + 1, sum, multi);
		}
		else {
			break;
		}
		sum -= x[i];
		multi /= x[i];
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n){
		int x[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		cout << getluckpacket(x, n, 0, 0, 1) << endl;
	}
	return 0;
}