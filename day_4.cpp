//����Ϊһ�У�һ��4���������ֱ�ΪA - B��B - C��A + B��B + C���ÿո������ ��Χ����-30��30֮��(������)��
#include <iostream>
using namespace std;
//A-B=a B-C=b A+B=c B+C=d
//ʵ����Ԫһ�η������
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (d - b) / 2 + b;
	int B2 = (a + c) / 2 - a;//B1��B2��Ϊ����֤ʽ����ȷ��
	if (B1 == B2){
		cout << A << " " << B1 << " " << C << endl;
	}
	else{
		cout << "No" << endl;
	}

}

//ʮ����ת��N����
#include <iostream>
#include <string>
#include <algorithm>
//Ҫ�����и������ڵ�ʱ��
using namespace std;

int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;

	bool flag = false;
	//��������Ǹ�������ת�������������
	if (m<0){
		m = 0 - m;
		flag = true;
	}
	//������ת���ɶ�Ӧ���ַ���ӵ�s
	while (m){
		s += table[m%n];
		m = m / n;
	}

	if (flag){
		s += '-';//��Ϊ������Ҫ׷��һ������
	}

	reverse(s.begin(), s.end());
	cout << s << endl;
}