//��ˮƿ����
//ע������ѭ��
#include <iostream>
using namespace std;
int Sum(int n)
{
	int sum = 0;
	while (n>1)//����ΪʲôҪ����1����Ϊ����2ʱ�����Խ�һ����ƿ�������ٻ�
	{
		int result = n / 3;
		int tmp = n % 3;//������ƿ�ȱ���
		sum += result;
		n = result + tmp;//*����һ�������ˮ�����Եõ���ƿ
		if (n == 2)
		{
			sum++;
			break;
		}
		//n����1ƿʱ����������������ѭ����
		//�ߵ�����˵��n����2�������Զһ�,�ظ�֮ǰ�������������м�
	}
	return sum;
}
int main()
{
	int n;
	while (cin >> n){
		cout << Sum(n) << endl;
	}
	return 0;
}

//�����ַ�����������Ӵ�
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b){

		if (a.size() > b.size())
		{
			swap(a, b);
		}

		int len1 = a.size(), len2 = b.size();
		int i, j, start = 0, max = 0;

		vector<vector<int> > MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		{
			for (j = 1; j <= len2; j++)
			{
				if (a[i - 1] == b[j - 1])
				{
					MCS[i][j] = MCS[i - 1][j - 1] + 1;
				}
				if (MCS[i][j]>max)
				{
					max = MCS[i][j];
					start = i - max;
				}
			}
		}
		cout << a.substr(start, max) << endl;
	}
	return 0;
}
