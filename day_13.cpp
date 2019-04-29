//��������
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
//			//�����ո�˵����һ������
//			if (str[i] == ' ')
//			{
//				count++;
//			}
//			//����˫���ţ�����һ��˫���ţ�ֱ���ҵ���һ��˫����
//			if (str[i] == '"')
//			{
//				do
//				{
//					i++;
//				} while (str[i] == '"');
//			}
//		}
//		//�Կո���㻮�ֲ������������������ȿո�����1
//		cout << count + 1 << endl;
//		//��flag��־�Ƿ����˫���š�0��ʾ��˫����
//		//˫�����еĿո�Ҫ��ӡ����
//		//�����ı�flag��ֵ
//		int flag = 1;
//		for (int i = 0; i < str.size(); i++)
//		{
//			//��˫���ţ���flagz��Ϊ0��������һ��˫��������Ϊ1
//			if (str[i] == '"')
//				flag ^= 1;
//			//˫���ź���ͨ�ո񲻴�ӡ
//			if (str[i] != ' ' && str[i] != '"')
//			{
//				cout << str[i];
//			}
//			//˫�����еĿո�Ҫ��ӡ
//			if (str[i] == ' ' && (!flag))
//			{
//				cout << str[i];
//			}
//			//����˫����֮��Ŀո�;ͻ���
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

//��ʯ��   ����Լ��
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