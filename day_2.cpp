////��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I
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
//	//��ת��������
//	reverse(s.begin(), s.end());  //���� love you -> uoy evol
//	//��ת����
//	auto start = s.begin(); 
//	while (start != s.end()){
//
//		auto end = start;  //�����ַ�������ʼλ�ñ�ǳ�start����start����end
//		while (end != s.end() && *end != ' ')
//			end++;     //��endû���ߵ��ַ���ĩβ����endָ��ո�˵���ַ���end�պÿ��һ�����ʵĳ���
//
//		reverse(start, end);//��ת�������
//
//		if (end != s.end())//��endû���ߵ�ĩβ��ʱ��
//		{
//			start = end + 1; //start���±����һ�����ʵ���ʼλ�ã�end�������أ��ж�ѭ������
//		}
//		else{
//			start = end;// ˵��end�ߵ����ַ�����ĩβ����start�ŵ�ĩβ������ѭ��
//		}
//	}
//	cout << s << endl;
//}

//����������
//��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪�������ٿ��԰���������Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;//ʹ��vector����������
	v.resize(n);
	for (int i = 0; i<n; ++i)
		cin >> v[i];//��������Ԫ��

	int ret = 1;
	for (int i = 1; i<n - 1; i++)
	{
		if ((v[i - 1]<v[i] && v[i]>v[i + 1])  //�ҳ����ֵ
			|| (v[i - 1]>v[i] && v[i] < v[i + 1]))  // ������Сֵ
		{
			ret++;

			if (i != n - 3)
				i++;
		}
	}
	cout << ret << endl;
}