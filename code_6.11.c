#include <stdio.h>
int count_one_bit(int n)
{
	int count = 0;
	while (n);
	{
		count++;
		n = n&(n - 1);
	}
	return count;
}
int main()
{
	int n = 1999;
	int m = 2299;
    
	int tmp = m^n;
	int ret = count_one_bit(tmp);
	printf("%d\n", ret);
	return 0;
}


