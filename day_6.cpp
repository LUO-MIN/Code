//不要二  W*H的网格中，任意两个格子的坐标的欧几里得距离不等于2
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//	int w, h;
//	int res = 0;
//	cin >> w >> h;
//	vector<vector<int> > a;
//	a.resize(w);
//	for (auto& e : a)
//		e.resize(h, 1);
//	for (int i = 0; i<w; i++)
//	{
//		for (int j = 0; j<h; j++)
//		{
//			if (a[i][j] == 1)
//			{
//				res++;
//				if ((i + 2)<w)
//				{
//					a[i + 2][j] = 0;
//				}
//				if ((j + 2)<h)
//				{
//					a[i][j + 2] = 0;
//				}
//			}
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << res;
//	return 0;
//}

//地下迷宫
#include <iostream>
#include <vector>

#define VISITED 2
using namespace std;

int m, n, P;
int maze[10][10];//迷宫地图
int dir[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };//四个移动方向
int cost[4] = { -1, -1, -3, 0 };//上下左右移动的体力值的
int final_P = -200; //剩余的体力值，初始值为最小的数

//存储到各点的数据结构
struct mazePoint{
	mazePoint(int _x, int _y)
	:x(_x), y(_y)
	{}
	int x, y;
};
//存储每次遍历的路径
vector<mazePoint> pathStack;
//存储最终最优路径
vector<mazePoint> minCostPath;

//函数：打印路径
void printPath(const vector<mazePoint>& path)
{
	for (int i = 0; i<path.size(); ++i)
	{
		cout << "[" << path[i].x << "," << path[i].y << "]";
		if (i<path.size() - 1)
		{
			cout << ",";
		}
	}
}
//函数：寻找足最优路径
void search(int x, int y, int cur_P){
	//将当前路径标记为VISITED
	pathStack.push_back(mazePoint(x, y));
	maze[x][y] = VISITED;

	//如果当前出口为且当前体力值>=0,则更新final_P与minCosPath,并返回
	if (x == 0 && y == m - 1 && cur_P >= 0)
	{
		if (cur_P>final_P)
		{
			final_P = cur_P;
			minCostPath = pathStack;
		}
		pathStack.pop_back();
		maze[x][y] = 1;
		return;
	}

	if (cur_P>0)
	{
		for (int i = 0; i<4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			int nP = cur_P + cost[i];
			if (nx >= 0 && nx<n &&ny>=0&& ny<m && maze[nx][ny] == 0)
			{
				search(nx, ny, nP);
			}
		}
	}
	pathStack.pop_back();
	maze[x][y] = 1;

}
int main()
{

	cin >> n >> m >> P;
	for (int i = 0; i<n; ++i)
		for (int j = 0; j<m; ++j)
			cin >> maze[i][j];

	search(0, 0, P);

	if (final_P != -200)
	
		printPath(minCostPath);
	
	else
		cout << "Can not escape!";
	

	return 0;
}
 