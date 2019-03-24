#include <stdio.h>

int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main()
{
	int a = 4;
	int b = 7;
	int c = 0;
	c = Add(a, b);
	printf("c = %d", c);
	return 0;

}