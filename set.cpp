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
	//1.key/value  ͨ���ؼ��ֲ���ӳ�������Ϣvalue
	std::map<std::string, std::string> dict;
	dict.insert(std::pair<std::string, std::string>("sort", "����"));
	//std::pair<std::string, std::string>��һ��ģ������,
	dict.insert(std::make_pair("tree", "��"));
	//��һ������ģ�壬�������ι��캯��

	std::map<std::string, std::string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		//cout << *dit << endl;  ���ﲻ֧�������ָ��ָ�����һ������㣨����������Ľṹ�����������������һ��ֵ����������֮��ȡ����������������ݣ���ʱ��operator*�����õ�ֵ��һ���ṹ�壬����һ��pair�������޷��������������Ļ���ȡ��pair�����ֵ
	     //cout <<(*dit).first << ":"<<(*dit).second<<endl;
		//����
		cout << dit->first << "��" << dit->second << endl;
		 ++dit;
	}
	cout << endl;


	//ע�⣺���뺯�����Ѿ����ڵľͲ��ٲ��룬����ֻ��keyֵ����valueֵ
	//ͳ��ˮ���ĸ���
	std::string strs[] = { "ƻ��", "�㽶", "�㽶", "ƻ��","����", "��" };
	std::map<std::string, int> countmap;
	
	//for (const auto& str : strs)//��strs�е�ÿһ��Ԫ�أ�����str
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
	// 1.key  ���ҹؼ����ڲ���
	// 2.����&ȥ��  ������ֵ��ԭ�������Ѿ����ڣ��Ͳ��ٲ�����
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

	it =s.find(5);//���Ӷ���O(logN)���������������Ļ����ϸ��ݹ��ɲ���
	//it = std::find(s.begin(), s.end(), 5);//�������������������������Ԫ�أ�ʱ�临�Ӷ���O(N)
	/*�ڴ����������£�����ϴ�*/

	if (it != s.end())
	{
		cout << "�ҵ���" << endl;
		s.erase(it);//�ҵ��˲���ɾ��������ȽϺ���
	}


	//s.erase(it);//ֻ��ɾ�����е�ֵ�����ɾ���Ķ��󲻴��ڣ���ô�ᱨ��
	s.erase(3);//Ҳ����ɾ�������ɾ����ֵ�����ھͲ�ɾ��������� 
	for (auto e : s)
	{
		cout << e << endl;
	}
	cout << endl;


	//s.swap()����ֱ�ӽ������ڵ��ָ��
	//��֧���޸ģ��޸�֮��ͻ�ı��������������Ͳ���׼ȷ������


	//���Բ���
	//���򵫲�ȥ��
	std::multiset<int> ms;
	ms.insert(4);
	ms.insert(1);
	ms.insert(8);
	ms.insert(3);
	ms.insert(12);
	ms.insert(6);
	ms.insert(8);
	ms.insert(10);

	auto mit = ms.find(8);//��set��find������multiset��find�ҵ�Ŀ��ֵ֮�󻹻�����ң�������ظ���ֵ��������е�Ŀ��ֵ���ҳ���
	if (mit != ms.end())
	{
		cout << "�ҵ���" << endl;
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