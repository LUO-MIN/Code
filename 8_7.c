//下列给定程序中，函数fun的功能是：把形参a所指数组中的奇数按原顺序依次存放到a[0]、a[1]、a[2]…中，把偶数从数组中删除，奇数个数通过函数值返回。 例如，若a所指数组中的数据最初排列为：9, 1, 4, 2, 3, 6, 5, 8, 7，删除偶数后，a所指数组中的数据为：9, 1, 3, 5, 7，返回值为5。

#include<stdio.h>
#define N 9
int fun(int a[], int n)
{
	int i, j;
	j = 0;
	for (i = 0; i<n; i++)
		/**********found**********/
	if (a[i] % 2 == 1)
	{
		/**********found**********/
		a[j] = a[i];
		j++;
	}
	/**********found**********/
	return i;
}
main()
{
	int b[N] = { 9, 1, 4, 2, 3, 6, 5, 8, 7 }, i, n;
	printf("\nThe original data:\n");
	for (i = 0; i<N; i++)
		printf("% 4d", b[i]);
	printf("\n");
	n = fun(b, N);
	printf("\nThe number of odd:% d\n", n);
	printf("\nThe odd number: \n");
	for (i = 0; i<n; i++)
		printf("%4d", b[i]);
	printf("\n");
}

