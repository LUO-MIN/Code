////斐波那契数列n项到m项求和
////误区：数据类型不够大，装太大的数，还是需要数组解决
//#include <iostream>
//using namespace std;
//long long int n[85] = { 1, 1, 2, 3, 5 };//数组要在两个函数中调用，要声明成全局的
//
//long long int FibSum(int from, int to)
//{
//	long long int sum = 0;//不要忘记初始化
//	for (int i = from - 1; i<to; i++)
//	{
//		sum += n[i];
//	}
//	return sum;
//}
//
//int main()
//{
//	int from, to;
//	for (int i = 5; i<81; i++)
//	{
//		n[i] = n[i - 1] + n[i - 2];
//	}
//	while (cin >> from >> to){
//		cout << FibSum(from, to) << endl;
//	}
//}

//剪花布条（连续子串在另一串中的个数）
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t){
		int count = 0;
		size_t pos = 0;
		while ((pos = s.find(t, pos)) != string::npos)
		{
			pos += t.size();
			count++;
		}
		cout << count << endl;
	}
}