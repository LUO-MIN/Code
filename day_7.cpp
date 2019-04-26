//距离N最近的斐波那切数
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


//括号匹配
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		//用栈结构实现，栈中存左括号，当遇到右括号，检查是否有左括号
		//如果有则出栈，没有则说明不匹配
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