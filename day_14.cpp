//�������ڵ�������ת��
#include <iostream>
using namespace std;
int main()
{
	//��ÿ���ۼƵ�������������
	int array[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

	int year;
	int mouth;
	int day;
	int sum = 0;
	while (cin >> year >> mouth >> day){
		sum = 0;
		sum += array[mouth - 2];//��Ϊ���µ�������day����
		sum += day;
		if (mouth > 2)//�·ݴ���2���ж�ʱƽ�껹������
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				sum += 1;//�����ƽ���һ��
			}
		}
		cout << sum << endl;
	}
}

//���˴��ӣ�ץС��
//1.��С�����ţ�����������
//x[ ]������������С��   n:�������  pos:��ǰ����λ��  sum��Ŀǰλ�õ��ۼӺ�    multi:ĿǰΪλ�õ��ۻ�
#include <iostream>
#include <algorithm>

using namespace std;

int getluckpacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	for (int i = pos; i < n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum>multi)
		{
			count += 1 + getluckpacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1)
		{
			count += getluckpacket(x, n, i + 1, sum, multi);
		}
		else {
			break;
		}
		sum -= x[i];
		multi /= x[i];
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n){
		int x[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		cout << getluckpacket(x, n, 0, 0, 1) << endl;
	}
	return 0;
}