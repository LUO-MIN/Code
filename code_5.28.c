//2. ¼ÆËã1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ¡­¡­ + 1 / 99 - 1 / 100 µÄÖµ¡£
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float s1 = 0;
	float s2 = 0;
	float sum = 0;
	int i = 1;
	float j = 1.0;

	for (i = 1; i <=100; i++)
	{   
		if (i % 2 == 1)
		{
			
			s1 += j / i;
		}
		else
		{
			s2 += -j / i;
		}
			
	}
	sum = s1 + s2;
	printf("sum = %lf\n", sum);
	
	return 0;

}
