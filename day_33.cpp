////쳲���������n�m�����
////�������������Ͳ�����װ̫�������������Ҫ������
//#include <iostream>
//using namespace std;
//long long int n[85] = { 1, 1, 2, 3, 5 };//����Ҫ�����������е��ã�Ҫ������ȫ�ֵ�
//
//long long int FibSum(int from, int to)
//{
//	long long int sum = 0;//��Ҫ���ǳ�ʼ��
//	for (int i = from - 1; i<to; i++)
//	{
//		sum += n[i];
//	}
//	return sum;
//}
//
//int main()
//{
//	int from, to;
//	for (int i = 5; i<81; i++)
//	{
//		n[i] = n[i - 1] + n[i - 2];
//	}
//	while (cin >> from >> to){
//		cout << FibSum(from, to) << endl;
//	}
//}

//���������������Ӵ�����һ���еĸ�����
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t){
		int count = 0;
		size_t pos = 0;
		while ((pos = s.find(t, pos)) != string::npos)
		{
			pos += t.size();
			count++;
		}
		cout << count << endl;
	}
}