 //�ַ������ҳ�����������ִ�
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, cur, res;
	cin >> str;
	for (int i = 0; i <= str.length(); i++)
	{
		//���ִ���+=��cur����ȥ
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else{
			if (res.length()<cur.length())//��cur���浽res�У��ȵ�������һ�����ִ�ʱ���ٴαȽϣ�ȡ�������ģ�
			{
				res = cur;
			}
			else{
				cur.clear();
			}
		}
	}
	cout << res;
}



//n��������ִ������ڵ���n/2����
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> vec;
	while (cin >> n)
		vec.push_back(n);//��������β��

	int count = 1;//��Ϊ����v[0]�Ƚ�
	int tmp = vec[0];//��v[0]����Ϊ�ڱ����������Ƚ�
	for (int i = 1; i<vec.size(); ++i)//�ӵڶ���Ԫ�رȽ�
	{
		if (vec[i] == tmp)
		{
			count++;
		}
		else{
			count--;
		}
		if (count == 0)
		{
			tmp = vec[i];//��Ϊ�ǳ��ִ�������n/2�ģ����Ե����һ���ᴫֵ��tmp��
			count++;
		}
	}

	cout << tmp << endl;
}
