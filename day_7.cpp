//����N�����쳲�������
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int a, b, c;
	int l, r;
	while (cin >> n){
		a = 0;
		b = 1;
		while (1){
			c = a + b;
			a = b;
			b = c;
			if (c<n)
			{
				l = n - c;
			}
			else{
				r = c - n;
				break;
			}
		}
		cout << min(l, r) << endl;
	}
}


//����ƥ��
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		//��ջ�ṹʵ�֣�ջ�д������ţ������������ţ�����Ƿ���������
		//��������ջ��û����˵����ƥ��
		stack<char> sc;
		for (auto ele : A){
			switch (ele){
			case '(':
				sc.push(ele);
				break;
			case ')':
			{
			 if (sc.empty() || sc.top() != '(')
				return false;
     		else
				sc.pop();
			}
			break;
			default:
			return false;

			}
		}
		return true;
	}
};