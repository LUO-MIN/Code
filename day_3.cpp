 //字符串中找出连续最长的数字串
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, cur, res;
	cin >> str;
	for (int i = 0; i <= str.length(); i++)
	{
		//数字串都+=到cur里面去
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else{
			if (res.length()<cur.length())//将cur保存到res中，等到遇到下一个数字串时，再次比较，取长度最大的，
			{
				res = cur;
			}
			else{
				cur.clear();
			}
		}
	}
	cout << res;
}



//n个数里出现次数大于等于n/2的数
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> vec;
	while (cin >> n)
		vec.push_back(n);//巧用数组尾插

	int count = 1;//因为是与v[0]比较
	int tmp = vec[0];//把v[0]设置为哨兵，依次向后比较
	for (int i = 1; i<vec.size(); ++i)//从第二个元素比较
	{
		if (vec[i] == tmp)
		{
			count++;
		}
		else{
			count--;
		}
		if (count == 0)
		{
			tmp = vec[i];//因为是出现次数大于n/2的，所以到最后一定会传值到tmp中
			count++;
		}
	}

	cout << tmp << endl;
}
