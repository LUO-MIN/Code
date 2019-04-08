
//找数根
//比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
//再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。
//每组数据数据包含一个正整数n（1≤n≤10E1000）注意这里的数据类型超过了任何整型的范围，只能用字符串来存储数据
//#include <iostream>
//#include <string> 
//using namespace std;
//int numroot(int n)
//{
//	int root = 0;
//	while (n){
//		root += n % 10;
//		n = n / 10;
//	}
//	while (root>9){
//		root = numroot(root); //巧妙运用递归
//	}
//	return root;
//}
//
//int main()
//{
//	string n;
//	while (cin >> n){
//		int sum = 0;
//		for (int i = 0; i < n.length(); i++)
//		{
//			sum += n[i] - '0';//转化成数字  //字符数字可以通过ASCII码转化成逻辑数字，
//		}
//
//
//		cout << numroot(sum) << endl;
//	}
//	return 0;
//}
