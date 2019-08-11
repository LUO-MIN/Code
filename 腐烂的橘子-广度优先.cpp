class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();

		queue<pair<int, int>> q;

		for (int i = 0; i<row; i++)
		{
			for (int j = 0; j<col; j++)
			{
				if (grid[i][j] == 2)
					q.push(make_pair(i, j));
			}
		}

		static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		int mintime = 0;
		while (!q.empty())
		{
			int sz = q.size();
			int flag = 0;
			while (sz--)
			{
				auto cur = q.front();
				q.pop();
				for (int k = 0; k<4; k++)
				{
					int x = cur.first + pos[k][0];
					int y = cur.second + pos[k][1];


					if (x<0 || x >= row || y<0 || y >= col || grid[x][y] != 1)
						continue;

					flag = 1;
					grid[x][y] = 2;
					q.push(make_pair(x, y));
				}
			}
			//ÓÐÐÂµÄ¸¯ÀÃ£¬++
			if (flag)
				++mintime;
		}

		for (int i = 0; i<row; i++)
		{
			for (int j = 0; j<col; j++)
			{
				if (grid[i][j] == 1)
					return -1;
			}
		}

		return mintime;
	}
};