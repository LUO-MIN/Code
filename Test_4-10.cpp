////�ж��ַ���B�Ƿ����ַ���A��
////O(n*m)��ѯ�������ַ���A�е��ַ����ַ���B�е��ַ�һһ�Ƚ�
#include <iostream>
#include <string>

using namespace std;

int CompareString(string StringA, string StringB)
{
	unsigned int i, j;
	for (i = 0; i < StringA.length(); i++)
	{
		for(j = 0; j < StringB.length(); j++)
		{
			if (StringB[j] == StringB[i])
			{
				break;
			}

		}
		if (j == StringA.length())
		{
			cout << "false" << endl;
			return 0;
		}
		
	}
	cout << "ture" << endl;
	return 1;
}

int main()
{
	string StringA = "I like you";
	string StringB = "liyou";
	CompareString(StringA, StringB);
	return 0;
}

#include <iostream>
#include <string>

using namespace std;
int getCommonStrLength(char* pFirstStr, char* pSecondStr)
{
	int count = 0;
	
	if ((*pFirstStr == *pSecondStr) || (*pFirstStr + 32 == *pSecondStr) || (*pFirstStr-32==*pSecondStr))
	{
		count++;
		pFirstStr++;
		pSecondStr++;
	}
	else
	{
		pFirstStr++;
		getCommonStrLength(pFirstStr, pSecondStr);
	}
	return count;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		getCommonStrLength(str1.c_str, str2.c_str);
	}
}