#include <iostream>
//using namespace std;

using std::cout;
using std::endl;
#include <set>
using std::cout;
using std::endl;
#include <map>

template<class K, class V>
struct pair
{
	K first;
	V second;
};

template<class K,class V>
inline std::pair<K, V> make_pair(const K& k, const V& v)
{
	return std::make_pair<K, V>(k, v);
}

void test_map()
{
	//1.key/value  通过关键字查找映射关联信息value
	std::map<std::string, std::string> dict;
	dict.insert(std::pair<std::string, std::string>("sort", "排序"));
	//std::pair<std::string, std::string>是一个模板类型,
	dict.insert(std::make_pair("tree", "树"));
	//是一个函数模板，调用两次构造函数

	std::map<std::string, std::string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		//cout << *dit << endl;  这里不支持输出，指针指向的是一个个结点（类似于链表的结构，不过链表解引用是一个值），解引用之后取的是容器里面的数据，这时候operator*解引用的值是一个结构体，就是一个pair，所以无法输出，我们输出的话，取到pair里面的值
	     //cout <<(*dit).first << ":"<<(*dit).second<<endl;
		//或者
		cout << dit->first << "：" << dit->second << endl;
		 ++dit;
	}
	cout << endl;


	//注意：插入函数中已经存在的就不再插入，这里只看key值不看value值
	//统计水果的个数
	std::string strs[] = { "苹果", "香蕉", "香蕉", "苹果","西瓜", "梨" };
	std::map<std::string, int> countmap;
	
	//for (const auto& str : strs)//将strs中的每一个元素，赋给str
	//{
	//	auto it = countmap.find(str);
	//	if (it != countmap.end())
	//		it->second++;
	//	else
	//		countmap.insert(make_pair(str, 1));
	//}

    std::map<std::string, int>::iterator cit = countmap.begin();
	for (const auto& str : strs)
	{
		countmap[str]++;
	}



	 
	auto cit = countmap.begin();
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
	cout << endl;

	for (const auto& kv : countmap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

void test_set()
{
	// 1.key  查找关键字在不在
	// 2.排序&去重  当插入值在原序列中已经存在，就不再插入了
	std::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(8);
	s.insert(3);
	s.insert(8);
	s.insert(6);
	s.insert(8);
	s.insert(5);

	std::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it =s.find(5);//复杂度是O(logN)，在搜索二叉树的基础上根据规律查找
	//it = std::find(s.begin(), s.end(), 5);//适用于所有容器，会遍历所有元素，时间复杂度是O(N)
	/*在大数据量的下，差异较大*/

	if (it != s.end())
	{
		cout << "找到了" << endl;
		s.erase(it);//找到了才能删，放这里比较合适
	}


	//s.erase(it);//只能删除已有的值，如果删除的对象不存在，那么会报错
	s.erase(3);//也可以删除，入过删除的值不存在就不删，不会出错 
	for (auto e : s)
	{
		cout << e << endl;
	}
	cout << endl;


	//s.swap()函数直接交换根节点的指针
	//不支持修改，修改之后就会改变搜索二叉树，就不能准确搜索了


	//可以查找
	//排序但不去重
	std::multiset<int> ms;
	ms.insert(4);
	ms.insert(1);
	ms.insert(8);
	ms.insert(3);
	ms.insert(12);
	ms.insert(6);
	ms.insert(8);
	ms.insert(10);

	auto mit = ms.find(8);//与set的find的区别：multiset的find找到目标值之后还会继续找，如果有重复的值，会把所有的目标值都找出来
	if (mit != ms.end())
	{
		cout << "找到了" << endl;
	}

	for (auto e : ms)
	{
		cout << e << endl;
	}
	cout << endl;
}


int main()
{
	test_map();
	test_set();
	return 0;
}