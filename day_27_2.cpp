//位运算求加法
//class Solution {
//public:
//	int Add(int num1, int num2)
//	{
//		int tmp = 0;
//		while (num2){
//			tmp = num1^num2;
//			num2 = (num1&num2) << 1;
//			num1 = tmp;
//		}
//		return num1;
//	}
//};

//三角形
#include <iostream>
#include <string>
#define ADD(x, y)  ((x)+(y))
#define CMP(x, y)  ((x)>(y))
int main()
{
	long a, b, c;
	while (std::cin >> a >> b >> c){
		if (CMP(ADD(a, b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b))
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}

	return 0;
}