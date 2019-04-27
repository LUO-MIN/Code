//���������������������
class LCA {
public:
	int getLCA(int a, int b) {
		/*���������ĸ��ڵ����ӽڵ�Ĺ�ϵ��
		root = child/2;
		*/
		while (a != b)
		{
			if (a>b)
				a = a / 2;
			else
				b = b / 2;
		}
		return b;
	}
};

//�������bitλ
#include <iostream>
#include <algorithm>
using namespace std;
int MoreLong(int n)
{
	int count = 0;
	int maxcount = 0;
	while (n)
	{
		if (n & 1){
			count++;
		}
		else{
			count = 0;

		}
		maxcount = max(maxcount, count);
		n = (n >> 1);

	}
	return maxcount;


}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << MoreLong(n) << endl;
	}
	return 0;
}