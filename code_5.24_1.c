//3.��10���������е����ֵ��
#include <stdio.h>
int main()
{
	int i, max;
	int a[10];
   printf("����10������ֵ��");
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