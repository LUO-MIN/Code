//��100-200֮���ȫ������
#include<stdio.h>
#include<math.h>
int main()
{
	int i, j, m;
	for (i = 101; i < 200; i += 2)
	{
		j = sqrt(i);
		for (m = 2; m <= j;m++)
		if (i%j == 0)
			break;
		if (m>j)
			printf("%d ", i);
	}
	return 0;
}