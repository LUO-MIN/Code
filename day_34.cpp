//��������
//������С���Ӹ�һ����һֻ�����ε�쳲�����������
#include <iostream>
using namespace std;
int main()
{
	long long int a[95] = {1,2};//������Ԫ�ؽ�����ݹ��������
	int n;
	for (int i = 2; i < 95; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	while (cin >> n){
		cout << a[n - 1] << endl;
		
	}
}


