//��Ҫ��  W*H�������У������������ӵ������ŷ����þ��벻����2
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

//�����Թ�
#include <iostream>
#include <vector>

#define VISITED 2
using namespace std;

int m, n, P;
int maze[10][10];//�Թ���ͼ
int dir[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };//�ĸ��ƶ�����
int cost[4] = { -1, -1, -3, 0 };//���������ƶ�������ֵ��
int final_P = -200; //ʣ�������ֵ����ʼֵΪ��С����

//�洢����������ݽṹ
struct mazePoint{
	mazePoint(int _x, int _y)
	:x(_x), y(_y)
	{}
	int x, y;
};
//�洢ÿ�α�����·��
vector<mazePoint> pathStack;
//�洢��������·��
vector<mazePoint> minCostPath;

//��������ӡ·��
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
//������Ѱ��������·��
void search(int x, int y, int cur_P){
	//����ǰ·�����ΪVISITED
	pathStack.push_back(mazePoint(x, y));
	maze[x][y] = VISITED;

	//�����ǰ����Ϊ�ҵ�ǰ����ֵ>=0,�����final_P��minCosPath,������
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
 