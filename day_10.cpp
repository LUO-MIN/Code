//井字棋
//对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
//给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为 - 1代表是对方玩家的棋子。
//class Board {
//public:
//	bool checkWon(vector<vector<int> > board) {
//		int row = board.size();
//		int i, j, sum;
//		for (int i = 0; i<row; i++)
//		{
//			sum = 0;
//			for (int j = 0; j<row; j++)
//			{
//				sum += board[i][j];
//			}
//			if (sum == row)
//			{
//				return true;
//			}
//		}
//
//		for (int i = 0; i<row; i++)
//		{
//			sum = 0;
//			for (int j = 0; j<row; j++)
//			{
//				sum += board[j][i];
//			}
//			if (sum == row)
//			{
//				return true;
//			}
//		}
//
//
//		sum = 0;
//		for (int i = 0; i<row; i++)
//		{
//			sum += board[i][i];
//		}
//		if (sum == row)
//		{
//			return true;
//		}
//
//
//		sum = 0;
//		for (int i = 0; i<row; i++)
//		{
//			sum += board[i][row - i - 1];
//		}
//		if (sum == row)
//		{
//			return true;
//		}
//		return false;
//	}
//};


//密码等级
#include <iostream>
#include <string>
using namespace std;

int numChar(string str, int k)
{
	//根据ASCII码判断大小写
	int small = 0;//小写个数
	int big = 0;//大写个数
	for (int i = 0; i<k; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			small++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			big++;
		}
	}
	if (small + big == 0)
	{
		return 0;
	}
	else if (small == k || big == k)
	{
		return 10;
	}
	else if (small > 0 && big > 0)
	{
		return 20;
	}
	return 0;
}

int numNumber(string str, int k)
{
	int count = 0;
	for (int i = 0; i<k; i++)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
		{
			count++;
		}
	}
	if (count == 0)
	{
		return 0;
	}
	else if (count == 1)
	{
		return 10;
	}
	else{
		return 20;
	}
}
int numSymbol(string str, int k)
{
	int count = 0;
	for (int i = 0; i<k; i++)
	{
		if (!(str[i] >= 'a' && str[i] <= 'z') &&
			!(str[i] >= 'A' && str[i] <= 'Z') &&
			!(str[i] - '0' >= 0 && str[i] - '0' <= 9))
		{
			count++;
		}

	}
	if (count == 0)
	{
		return 0;
	}
	else if (count == 1)
	{
		return 10;
	}
	else{
		return 25;
	}
}

int main()
{
	string str;
	while (cin >> str){
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		//判断长度，计算长度的等级
		int k = str.size();
		if (k <= 4)
		{
			sum1 = 5;
		}
		else if (k >= 8){
			sum1 = 25;
		}
		else{
			sum1 = 10;
		}

		sum2 = numChar(str, k);
		sum3 = numNumber(str, k);
		sum4 = numSymbol(str, k);
		if (sum2 >0 && sum3 > 0 && sum4 > 0)
		{
			if (sum2 == 10)
			{
				sum5 = 3;
			}
			else{
				sum5 = 5;
			}
		}
		else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
		{
			sum5 = 2;
		}

		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			printf("VERY_SECURE\n");
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
			printf("SECURE\n");
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			printf("VERY_STRONG\n");
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
			printf("STRONG\n");
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
			printf("AVERAGE\n");
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
			printf("WEAK\n");
		else
			printf("VERY_WEAK\n");
	}
	return 0;
}