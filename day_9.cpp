//另类加法
//不用+，-，*，/计算两个数的和
//利用异或，异或的运算规则与加法相似
//异或与二进制的 不带进位 的加法相同
//与运算与二进制的加法的进位
//所以两数相加：对应两数异或+两数相与
//特别的：进位要往上进一位，所以<<1
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

//求棋盘路径总数
#include <iostream>
using namespace std;
//递归
int pathNum(int n, int m)
{
	if (n>1 && m>1)
	{
		//行列都大于1时，
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	}
	else if (((m == 1) && (n >= 1)) || ((m >= 1) && (n == 1)))
	{
		//当行为1，或者列为1时
		return n + m;
	}
	else{
		//当行列都为空
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