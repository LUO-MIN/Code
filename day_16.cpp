//��ȫ��
#include <iostream>
#include <algorithm>
using namespace std;
//Լ��������Ա���sqrt(n)�ķ�Χ
int count(int n)
{
	int cnt = 0;
	if ((n<0) | (n>500000))
	{
		return -1;
	}
	else
	{
		for (int i= 2; i <= n; i++)
		{
			int sum = 0;
			//������Χ
			int sq = sqrt(i);
			for (int j = 2; j <= sq; j++)
			{
				if (i%j == 0)
				{
					if (i / j == j)
					{
						sum += j;
					}
					else
					{
						sum += j + (i / j);
					}
				}
			}
			if (sum + 1 == i)
			{
				cnt++;
			}
		}
		return cnt;
	}
}
int main()
{
	int num;
	while (cin >> num)
	{
		cout << count(num) << endl;
	}
	return 0;
}

//�˿��ƴ�С

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string line;
	while (getline(cin, line)){
		//��ը�����������ֱ�����
		if (line.find("joker JOKER") != -1)//����find����
			cout << "joker JOKER" << endl;
		else{
			int dash = line.find('-');
			//�ֿ�������
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			//��ȡ�ո�Ĵ���������Ϊc+1��
			int c1 = count(car1.begin(), car1.end(), ' ');
			int c2 = count(car2.begin(), car2.end(), ' ');
			//�õ���һ����
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2){
				//ֻҪ������ȣ����һ���ƴ�ļ�Ϊ��
				if (str.find(first1) > str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else
			{
				//��������ͬ��˵�����Ͳ���ͬ��ֻ��ը���������ƱȽ�
				//�������Ͷ��Ǵ����
				if (c1 == 3)
					cout << car1 << endl;
				else if (c2 == 3)
					cout << car2 << endl;
				else
					cout << "ERROR" << endl;

			}
		}
	}
}