//兔子问题：有一只兔子，从它出生的第三个月开始生兔子，一次生一只，问第几个月生多少只
//变形斐波那契数列   递归解决
#include <iostream>
using namespace std;

int getTotalCount(int month)
{
	int sum1 = 0;
	int sum2 = 0;
	if (month<3)
	{
		sum1 = 1;
	}
	else{

		sum2 = getTotalCount(month-1)+getTotalCount(month-2);
	}
	return sum1 + sum2;
}

int main()
{
	int month;
	while (cin >> month){
		cout <<getTotalCount(month)<<endl;
	}
}
#include <iostream>
using namespace std;

int main()
{
	int a[] = { 4, 0, 2, 3, 1 };
	int i, j, t;
	for (i = 1; i < 5; i++)
	{
		t = a[i];
		j = i - 1;
		while (j >= 0 && t>a[j])
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = t;
	}
	for (int k = 0; k < 5; k++){
		cout << a[k] << endl;
	}
}

//汽水瓶问题
#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum;
	while (cin >> n)
	{
		if (n<3)
		{
			sum = 0;
		}
		else{
			if (n % 2 == 0){
				sum = n % 3 + n / 3 + 1;
			}
			else{
				sum = n % 3 + n / 3;
			}
		}

		cout << sum << endl;
	}
	return 0;
}
