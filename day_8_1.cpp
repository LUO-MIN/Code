//����С������
//��С������=����֮���������Լ��
//���Լ������շת����� 
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int r;
	while (r = a%b){
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b){
		cout<<a*b/gcd(a, b)<<endl;
	}
}