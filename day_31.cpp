

//��ʽ�ֽ�
//�ÿ����ķ�ʽ�����Ч��

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	unsigned int a;

	while (cin >> a){
		cout << a<<' ' << "=" << ' ';
		for (size_t i = 2; i <= sqrt(a); i++)
		{
			while (a != i && a%i == 0)//
			{
				cout << i << ' ' << "*" << ' ';
				a = a / i;
			}
		}
		cout << a <<endl;
	}
}