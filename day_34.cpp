//兔子问题
//误区：小兔子隔一天生一只，变形的斐波那契额数列
#include <iostream>
using namespace std;
int main()
{
	long long int a[95] = {1,2};//用数组元素解决数据过大的问题
	int n;
	for (int i = 2; i < 95; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	while (cin >> n){
		cout << a[n - 1] << endl;
		
	}
}


//收件人列表

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	while (cin >> n){
		cin.get();
		string name;
		for (int i = 0; i < n; i++)
		{
			bool quote = false;
			getline(cin, name);
			if (name.find(',') != string::npos || name.find(' ') != string::npos)
			{
				quote = true;
			}
			if (quote){
				printf("\"");
			}

			printf("%s", name.c_str());

			if (quote){
				printf("\"");
			}

			if (i == n - 1){
				printf("\n");
			}
			else{
				printf(", ");
			}
		}
	}

}