//ϴ��
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

//MP3���
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;//��������
	string order;//����
	while (cin >> n >> order){
	//��n�׸���1��n��numΪ��ǰ������ţ�firstΪ��ǰ��Ļ��ʾҳ�ĵ�һ�׸����ı��
		int num = 1, first=1;
		if (n <= 4)//����������С��4ʱ�����÷�ҳ
		{
			for (int i = 0; i < order.size(); i++)
			{
				//��ǰ�ڵ�һ�׸��ʱ�����Ϸ�ҳ�������һ��
				if (num == 1 && order[i] == 'U')
				{
					num = n;
				}
				//��ǰ�����һ�׸�ʱ�����»���������ת����һ�׸�
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