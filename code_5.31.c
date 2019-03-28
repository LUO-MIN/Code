#include<stdio.h>
int main()
{
	int ch;
	int count = 0;
	while ((ch = getchar()) != EOF) //≈–∂œch «∑Òµ»”⁄-1
	{
		if (ch == '{')
		{
			count++;

		}
		if (ch == '}' && count == 0)
		{
			printf("≤ª∆•≈‰\n");
			return 0;
		}
		if (ch == '}' && count != 0)
		{
			count--;

		}
	}

	if (count == 0)
	{
		printf("∆•≈‰\n");

	}
	else
	{
		printf("≤ª∆•≈‰\n");
	}

	return 0;
}
