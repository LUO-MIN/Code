//组队竞赛
//链接：https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int n;
	while (cin >> n){
		long long sum;
		vector<int> a(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];  //
		}

		sort(a.begin(), a.end());//对数组进行排序
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];//三人一组，分为n组，此时数组已经有序，  
		}

		cout << sum << endl;
	}

}


//删除公共字符串
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//有空格的字符串不能用cin接受，因为cin遇到空格就结束了
	//OJ的IO输入字符串用getline比较好
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	//使用哈希映射思想，先统计str2字符出现的次数
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		//遍历str1，str[i]映射hashtable对应位置为0，则表示这个字符没有在str2出现过，就把不重复的字符+=到ret,
		//注意这里最好不要str1.erase(i),因为一边遍历，一边erase，容易出错
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}

	cout << ret << endl;
}