#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ch;
	while ((ch=getcher()) != EOF)
	{
		if (ch >= 'a'&&ch <= 'z')
		{
			ch = ch - 32;
			printf("%c", ch);
		}
		else if (ch>='A'&&ch <= 'Z')
		{
			ch = ch + 32;
			printf("%c", ch);
		}
		else if (ch>='0'&&ch <= '9')
		{
			printf("%c", ch);
		}
		else
		{
			;
		}
	}
	return 0;
		
}