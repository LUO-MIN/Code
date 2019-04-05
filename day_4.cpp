//输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在-30到30之间(闭区间)。
#include <iostream>
using namespace std;
//A-B=a B-C=b A+B=c B+C=d
//实质三元一次方程求解
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (d - b) / 2 + b;
	int B2 = (a + c) / 2 - a;//B1和B2是为了验证式子正确性
	if (B1 == B2){
		cout << A << " " << B1 << " " << C << endl;
	}
	else{
		cout << "No" << endl;
	}

}

//十进制转换N进制
#include <iostream>
#include <string>
#include <algorithm>
//要考虑有负数存在的时候，
using namespace std;

int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;

	bool flag = false;
	//考虑如果是负数，则转成正数，并标记
	if (m<0){
		m = 0 - m;
		flag = true;
	}
	//按进制转换成对应的字符添加到s
	while (m){
		s += table[m%n];
		m = m / n;
	}

	if (flag){
		s += '-';//当为负数，要追加一个负号
	}

	reverse(s.begin(), s.end());
	cout << s << endl;
}