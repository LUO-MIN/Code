#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

void Test_string1()
{
	//���ֳ�ʼ������
	string s1("Hello");
	string s2 = "world";
	//ʹ�ô��εĹ��캯����ʼ��  �﷨������ʽ���͵�ת��

	char str1[] = "string";//7���ֽ�
	char str2[] = "�ƴ�";//5   һ�����������ֽ�
}

void test_string2()
{
	string s1("Hello");
	string s2(s1);
	string s3("world");
	s1 = s3;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	string file("file.cpp");
	string s4(s3,1,3); 
	string s5(++file.begin(), --file.end());
	string path("c:\\test.c",4);//c:\t  ����һ��\��ת���ַ�

	cout << path << endl;
	cout << s5 << endl;
}
//
//void  test_string3()
//{
//	string s1("hello");
//	string::reverse_iterator rit = s1.rbegin();//�������ַ�������
//	while (rit != s1.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}


//int StrToInt(const string& str)
//{
//	int value = 0;
//	string::const_reverse_iterator it = str.rbegin();//begin()�Ƿ�const
//	while (it != str.rend())
//	{
//	
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//	return value;
//
//}

//int StrToInt(const string& str)
//{
//	int value = 0;
//	auto it = str.rbegin();
//	while (it != str.rend())
//	{
//
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//	return value;
//
//}

//�����ַ���
//"1234"
//int StrToInt1(string str)
//{
//	int value = 0;
//	for (size_t i = 0; i < str.size(); ++i)
//	{
//		value *= 10;
//		value += str[i] - '0';
//		cout << str[i] << " ";
//		�ȼ���cout << str.operator[](i) << " ";
//	}
//	cout << endl;
//
//	return value;
//}
//
//�ڶ��ֱ�����ʽ
//int StrToInt2(string str)
//{
//	int value = 0;
//	//�������������ƻ���װ������·�������
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//
//	return value;
//}

//����vector

 /*vector<int> v;
 v.push_back(1);
 v.push_back(2);
 v.push_back(3);
 vector<int>::iterator vit = v.begin();
 while (vit!=v.end())
 {
	 cout << *vit << " ";
	 ++vit;
 }
 cout << endl;

 list<int> l;
 l.push_back(1);
 l.push_back(2);
 l.push_back(3);
 list<int>::iterator lit = l.begin();
 while (lit != l.end())
 {
	 cout << *lit << endl;
	 ++lit;
 }
*/

//void test_string3()
//{
//	string str("1234");
//	cout << StrToInt("1234") << endl;
//	
//}

void test_string4()
{
	string s1("hello");
	s1.push_back(' ');
	s1.push_back('m');
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;//���ݴ��°�2����

}
void test_string5()
{
	//capacity���1.5������
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n" << endl;
	s.reserve(100);
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

int main()
{
	test_string5();
	return 0;
}