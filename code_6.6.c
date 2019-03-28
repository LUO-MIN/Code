
#include <stdio.h>
#include <string.h>
int main()
{
	int ch = 0;
	while ((ch =getchar())!= EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			putchar(ch - 32);
		}
		else if (ch >= 'A'&& ch <= 'Z')
		{
			putchar(ch + 32);
		}
		else if (ch >= '0'&& ch <= '9')
		{
			;
		}
		else
		{
			putchar(ch);
		}
	}
	return 0;
}
