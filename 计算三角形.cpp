#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int a, b, c;
	double s;
	double area;
	scanf("%d,%d,%d", &a, &b, &c);

	s = (a + b + c) / 2;

	area = sqrt(s*(s - a)*(s - b)*(s - c));
	printf("The area of the triangle is %2.2lf\n",area);

}