//实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
#include <stdio.h>
#include <string.h>
//暴力移位法
void left_move(char* str, int k)
{
	int len = 0;
	int i = 0;
	while (k--)
	{
		//把一个保存起来
		char tmp = *str;//创建临时变量存放字符串
		//把后面的向前移动
		len = strlen(str);//求字符串长度
		for (i = 0; i < len - 1; i++)
		{
			*(str + i) = *(str + 1 + i);
		}
		//保存的数据放在最后
		*(str + len - 1) = tmp;
	}
}
int main()
{
	//abcdef
	//bcdefa
	//cdefab
	char a[] = "abcdef";
	left_move(a, 2);//传递字符串和需要旋转的长度。
		printf("%s\n", a);
	return 0;
}

//三步翻转
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
	reverse(a,a+k-1);//逆序前半部分,即前两节
	reverse(a+k,a+len-1);//逆序后半部分，后两节
	reverse(a,a+len-1);//逆序整个串
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

//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
#include <stdio.h>
#include <string.h>

int is_left_move(char* str1, char* str2)
{//判断字符串a连接自身个长度之后，b是否为a的子串，如果是，那么b就是反转过后的a
	int len1 = strlen(str1);//a的长度
	int len2 = strlen(str2);//b的长度
	if (len1 != len2)//如果a,b 长度不相等，那b一定不是a反转的得到的。
		return 0;
	strncat(str1, str1, len1);//将字符串a自身连接,注意，strcat不能直接用于字符串自身连接，会导致\0被占用，一直死循环。
	if (strstr(str1, str2))//strstr:在字符串a中找字符串b第一次出现的位置
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
		printf("是\n");
	}
	else
	{
		printf("否");
	}
	return 0;
}



