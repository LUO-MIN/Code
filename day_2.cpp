////将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s);
//
//	//翻转整个句子
//	reverse(s.begin(), s.end());  //比如 love you -> uoy evol
//	//翻转单词
//	auto start = s.begin(); 
//	while (start != s.end()){
//
//		auto end = start;  //将新字符串的起始位置标记成start，将start赋给end
//		while (end != s.end() && *end != ' ')
//			end++;     //当end没有走到字符串末尾，且end指向空格，说明字符串end刚好跨过一个单词的长度
//
//		reverse(start, end);//翻转这个单词
//
//		if (end != s.end())//当end没有走到末尾的时候
//		{
//			start = end + 1; //start重新标记下一个单词的起始位置，end继续返回，判断循环条件
//		}
//		else{
//			start = end;// 说明end走到了字符串的末尾，将start放到末尾，跳出循环
//		}
//	}
//	cout << s << endl;
//}

//排序子序列
//定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 牛牛想知道他最少可以把这个数组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;//使用vector数组存放数组
	v.resize(n);
	for (int i = 0; i<n; ++i)
		cin >> v[i];//输入数组元素

	int ret = 1;
	for (int i = 1; i<n - 1; i++)
	{
		if ((v[i - 1]<v[i] && v[i]>v[i + 1])  //找出最大值
			|| (v[i - 1]>v[i] && v[i] < v[i + 1]))  // 或者最小值
		{
			ret++;

			if (i != n - 3)
				i++;
		}
	}
	cout << ret << endl;
}