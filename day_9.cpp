//����ӷ�
//����+��-��*��/�����������ĺ�
//��������������������ӷ�����
//���������Ƶ� ������λ �ļӷ���ͬ
//������������Ƶļӷ��Ľ�λ
//����������ӣ���Ӧ�������+��������
//�ر�ģ���λҪ���Ͻ�һλ������<<1
class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0;
		int carry = 0;
		while (B){
			sum = A^B;
			carry = (A&B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};

//������·������
#include <iostream>
using namespace std;
//�ݹ�
int pathNum(int n, int m)
{
	if (n>1 && m>1)
	{
		//���ж�����1ʱ��
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	}
	else if (((m == 1) && (n >= 1)) || ((m >= 1) && (n == 1)))
	{
		//����Ϊ1��������Ϊ1ʱ
		return n + m;
	}
	else{
		//�����ж�Ϊ��
		return 0;
	}
}

int main()
{
	int n, m;
	while (cin >> n >> m){
		cout << pathNum(n, m) << endl;
	}
	return 0;
}