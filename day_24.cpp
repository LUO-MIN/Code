//年终奖 二维数组

class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		int length = board.size();
		int wideth = board[0].size();
		vector<vector<int>> allPrice;
		for (int i = 0; i<length; i++)
		{
			vector<int> tmp(wideth, 0);
			allPrice.push_back(tmp);
		}
		allPrice[0][0] = board[0][0];
		for (int i = 0; i<length; i++)
		{
			for (int j = 0; j<wideth; j++)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}
				else if (i == 0)
				{
					allPrice[i][j] = allPrice[i][j - 1] + board[i][j];
				}
				else if (j == 0)
				{
					allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
				}
				else{
					allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i - 1][j]) + board[i][j];
				}
			}
		}
		return allPrice[length - 1][wideth - 1];
	}
};

//迷宫问题
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> maze;
vector<vector<int>> path_temp;
vector<vector<int>> path_best;

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;
	path_temp.push_back({ i, j });

	if (i == N - 1 && j == M - 1)
	if (path_best.empty() || path_temp.size()< path_best.size())
		path_best = path_temp;
	if (i - 1 >= 0 && maze[i - 1][j] == 0)
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)
		MazeTrack(i + 1, j);
	if (j - 1 >= M && maze[i][j - 1] == 0)
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)
		MazeTrack(i, j + 1);
	maze[i][j] = 0;
	path_temp.pop_back();
}

int main()
{
	while (cin >> N >> M){
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto &i : maze)
		for (auto &j : i)
			cin >> j;
		MazeTrack(0, 0);
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
	}
	return 0;
}