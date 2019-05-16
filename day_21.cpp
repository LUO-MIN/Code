//洗牌
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
		for (int i = 0; i<num; ++i)
		{
			cin >> table[i];
		}

		while (k--)
		{
			vector<int> n1(table.begin(), table.end());
			for (int i = 0; i<n; ++i)
			{
				table[2 * i] = n1[i];
				table[2 * i + 1] = n1[i + n];

			}
		}
		for (int i = 0; i<num - 1; ++i)
			cout << table[i] << " ";
		cout << table[num - 1] << endl;
	}
	return 0;
}

//MP3光标
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;//歌曲数量
	string order;//命令
	while (cin >> n >> order){
	//将n首歌编号1到n，num为当前歌曲编号，first为当前屏幕显示页的第一首歌曲的编号
		int num = 1, first=1;
		if (n <= 4)//当歌曲总数小于4时，不用翻页
		{
			for (int i = 0; i < order.size(); i++)
			{
				//当前在第一首歌的时候，向上翻页，则到最后一首
				if (num == 1 && order[i] == 'U')
				{
					num = n;
				}
				//当前是最后一首歌时，向下滑动，则跳转到第一首歌
				else if (num == n && order[i] == 'D')
				{
					num = 1;
				}
				else if (order[i] == 'U')
				{
					num--;
				}
				else{
					num++;
				}
			}
			for (int i = 1; i <= n - 1; i++)
			{
				cout << i << ' ';
			}
			cout << n << endl;
			cout << num << endl;
		}
		else
		{
			for (int i = 0; i < order.size(); i++)
			{
				if (first == 1 && num == 1 && order[i] == 'U')
				{
					first = n - 3;
					num = n;
				}
				else if (first == n - 3 && num == n && order[i] == 'D')
				{
					first = 1;
					num = 1;
				}
				else if (first != 1 && num == first && order[i] == 'U')
				{
					first--;
					num--;
				}
				else if (first != n - 3 && num == first + 3 && order[i] == 'D')
				{
					first++;
					num++;
				}
				else if (order[i] == 'U')
				{
					num--;
				}
				else
				{
					num++;
				}
				
			}
			for (int i = first; i < first + 3; i++)
			{
				cout << i << ' ';
			}
			cout << first + 3 << endl;
			cout << num << endl;
		
		}
	}
	return 0;
}