//��Ӿ���
//���ӣ�https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int n;
	while (cin >> n){
		long long sum;
		vector<int> a(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];  //
		}

		sort(a.begin(), a.end());//�������������
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];//����һ�飬��Ϊn�飬��ʱ�����Ѿ�����  
		}

		cout << sum << endl;
	}

}


//ɾ�������ַ���
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//�пո���ַ���������cin���ܣ���Ϊcin�����ո�ͽ�����
	//OJ��IO�����ַ�����getline�ȽϺ�
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	//ʹ�ù�ϣӳ��˼�룬��ͳ��str2�ַ����ֵĴ���
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		//����str1��str[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ�û����str2���ֹ����ͰѲ��ظ����ַ�+=��ret,
		//ע��������ò�Ҫstr1.erase(i),��Ϊһ�߱�����һ��erase�����׳���
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}

	cout << ret << endl;
}