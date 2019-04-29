//参数解析
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string str;
//	while (getline(cin, str)){
//		int count = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			//遇到空格，说明是一个参数
//			if (str[i] == ' ')
//			{
//				count++;
//			}
//			//遇到双引号，找下一个双引号，直到找到下一个双引号
//			if (str[i] == '"')
//			{
//				do
//				{
//					i++;
//				} while (str[i] == '"');
//			}
//		}
//		//以空格计算划分参数个数，参数个数比空格数多1
//		cout << count + 1 << endl;
//		//用flag标志是否包含双引号。0表示有双引号
//		//双引号中的空格要打印出来
//		//用异或改变flag的值
//		int flag = 1;
//		for (int i = 0; i < str.size(); i++)
//		{
//			//有双引号，将flagz置为0；遇到下一个双引号再置为1
//			if (str[i] == '"')
//				flag ^= 1;
//			//双引号和普通空格不打印
//			if (str[i] != ' ' && str[i] != '"')
//			{
//				cout << str[i];
//			}
//			//双引号中的空格要打印
//			if (str[i] == ' ' && (!flag))
//			{
//				cout << str[i];
//			}
//			//遇到双引号之外的空格就就换行
//			if (str[i] == ' '&& flag)
//			{
//				cout << endl;
//			}
//			
//		}
//
//		cout << endl;
//	}
//	return 0;
//}

//跳石板   计算约数
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void divsorNum(int n, vector<int> &divNum)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			divNum.push_back(i);
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}

int Jump(int N, int M)
{
	vector<int> stepNum(M + 1, 0);
	stepNum[N] = 1;

	for (int i = N; i < M; i++)
	{
		vector<int> divNum;

		if (stepNum[i] == 0)
			continue;

		divsorNum(i, divNum);

		for (int j = 0; j < divNum.size(); j++)
		{
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[stepNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);
			else if ((divNum[j]+i)<=M){
				stepNum[divNum[j] + i] = stepNum[i] + 1;
			}
		}
	}
	if (stepNum[M] == 0)
	{
		return -1;
	}
	else
	{
		return stepNum[M] - 1;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
	return 0;
}