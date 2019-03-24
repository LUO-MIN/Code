//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
#include <stdio.h>
#include <string.h>
//������λ��
void left_move(char* str, int k)
{
	int len = 0;
	int i = 0;
	while (k--)
	{
		//��һ����������
		char tmp = *str;//������ʱ��������ַ���
		//�Ѻ������ǰ�ƶ�
		len = strlen(str);//���ַ�������
		for (i = 0; i < len - 1; i++)
		{
			*(str + i) = *(str + 1 + i);
		}
		//��������ݷ������
		*(str + len - 1) = tmp;
	}
}
int main()
{
	//abcdef
	//bcdefa
	//cdefab
	char a[] = "abcdef";
	left_move(a, 2);//�����ַ�������Ҫ��ת�ĳ��ȡ�
		printf("%s\n", a);
	return 0;
}

//������ת
#include <stdio.h>
#include <assert.h>
void reverse(char* left, char* right)
{
	assert(left&&right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char *a, int k)
{
	int len = strlen(a);
	reverse(a,a+k-1);//����ǰ�벿��,��ǰ����
	reverse(a+k,a+len-1);//�����벿�֣�������
	reverse(a,a+len-1);//����������
}
int main()
{
	//bafedc
	//cdefab
	char a[] = "abcdef";
	left_move(a, 2);
	printf("%s\n", a);
	return 0;
}

//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 �� AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
#include <stdio.h>
#include <string.h>

int is_left_move(char* str1, char* str2)
{//�ж��ַ���a�������������֮��b�Ƿ�Ϊa���Ӵ�������ǣ���ôb���Ƿ�ת�����a
	int len1 = strlen(str1);//a�ĳ���
	int len2 = strlen(str2);//b�ĳ���
	if (len1 != len2)//���a,b ���Ȳ���ȣ���bһ������a��ת�ĵõ��ġ�
		return 0;
	strncat(str1, str1, len1);//���ַ���a��������,ע�⣬strcat����ֱ�������ַ����������ӣ��ᵼ��\0��ռ�ã�һֱ��ѭ����
	if (strstr(str1, str2))//strstr:���ַ���a�����ַ���b��һ�γ��ֵ�λ��
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	/*while (len--)
	{
		left_move(str1, 1);

		if (strcmp(str1, str2) == 0);
		{
			return 1;
		}
	}
	return 0;
}*/
int main()
{
	char a[20] = "abcdef";
	char b[] = "bcdefa";
	int ret = is_left_move(a, b);
	if (ret == 1)
	{
		printf("��\n");
	}
	else
	{
		printf("��");
	}
	return 0;
}



