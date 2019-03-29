#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

void Test_string1()
{
	//两种初始化方法
	string s1("Hello");
	string s2 = "world";
	//使用带参的构造函数初始化  语法上有隐式类型的转换

	char str1[] = "string";//7个字节
	char str2[] = "财大";//5   一个汉字两个字节
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
	string path("c:\\test.c",4);//c:\t  其中一个\是转义字符

	cout << path << endl;
	cout << s5 << endl;
}
//
//void  test_string3()
//{
//	string s1("hello");
//	string::reverse_iterator rit = s1.rbegin();//迭代器字符串逆置
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
//	string::const_reverse_iterator it = str.rbegin();//begin()是非const
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

//遍历字符串
//"1234"
//int StrToInt1(string str)
//{
//	int value = 0;
//	for (size_t i = 0; i < str.size(); ++i)
//	{
//		value *= 10;
//		value += str[i] - '0';
//		cout << str[i] << " ";
//		等价于cout << str.operator[](i) << " ";
//	}
//	cout << endl;
//
//	return value;
//}
//
//第二种遍历方式
//int StrToInt2(string str)
//{
//	int value = 0;
//	//迭代器——不破坏封装的情况下访问容器
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

//举例vector

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
	cout << s1.capacity() << endl;//增容大致按2倍增

}
void test_string5()
{
	//capacity差不多1.5倍增容
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