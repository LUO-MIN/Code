#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int** generate(int numRows, int** columnSizes) {
	int i = 0;
	//���ٴ��������ǵĶ�ά����
	int **arr = (int **)malloc(numRows * sizeof(int*));
	for (i = 0; i<numRows; i++)
	{
		arr[i] = (int*)malloc(numRows*sizeof(int));
	}
	//Ϊÿһ�е�����Ԫ�ظ������ٿռ�
	*columnSizes = (int*)malloc(numRows* sizeof(int));
	for (i = 0; i<numRows; i++)
	{
		int j = 0;
		//��¼ÿ�е�����
		columnSizes[0][i] = i + 1;
		for (j = 0; j <= i; j++)
		{
			if (i == j || j == 0)
				arr[i][j] = 1;
			else if (i>1 && j>0)
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	return arr;
}
