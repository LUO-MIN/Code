//青蛙变态跳台阶
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法
//f(1)=1;
//f(2)=2; 一次跳一级跳两次，和一次跳两级
//f(3)=1+f(1)+f(2);一次跳三级，一次跳一级一次跳两级，一级和两级又有f(1)和f(2)种跳法
//f(n)=1+f(n-1)+f(n-2)+......+f(1)
class Solution {
public:
	int jumpFloorII(int number) {
		return 1 << (number - 1);//左移一位表示乘2
		//或者
		//return pow(2, number-1);
	}
};
//注意读题，这是一道类似斐波那契数列的一道题，但是能跳上n级台阶这一句，表示与斐波那契数列算法又有所区别，如果没有这一句，那么算法就与斐波那契相同。

//快到碗里来
//小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。
//现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。
//每组数据包含两个整数n (1≤n≤2^128) 和r (1≤r≤2^128)，分别代表喵的身长和碗的半径。
//注意数据类型；
#include <iostream>
using namespace std;

int main()
{
	double len, r;
	while (cin >> len >> r){
		if (len<r*3.14 * 2)
		{
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
}



