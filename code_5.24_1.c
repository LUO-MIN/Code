//3.求10个整数的中的最大值。
#include <stdio.h>
int main()
{
	int i, max;
	int a[10];
   printf("输入10个整数值：");
   for (i = 0; i < 10;i++)
	    scanf("%d", &a[i]);
        max = a[0];
   for (i = 0; i < 10; i++)
   {
	   if (a[i]> max)
		   max = a[i];
   }
   printf("%d\n", max);
	return 0;
}