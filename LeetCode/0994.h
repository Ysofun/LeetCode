#pragma once



class Solution {
public:

	int orangesRotting(vector<vector<int>>& grid) {
		queue<pair<int, int>> que;
		int n = grid.size(), m = grid[0].size();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 2)
				{
					que.push(make_pair(i, j));
				}
			}
		}

		int t = 0;
		do
		{
			queue<pair<int, int>> que2;
			que2.swap(que);

			while (!que2.empty())
			{
				pair<int, int> temp = que2.front();
				int x = temp.first, y = temp.second;
				que2.pop();

				if (x >= 1 && grid[x - 1][y] == 1)
				{
					grid[x - 1][y] = 2;
					que.emplace(make_pair(x - 1, y));
				}

				if (x < n - 1 && grid[x + 1][y] == 1)
				{
					grid[x + 1][y] = 2;
					que.emplace(make_pair(x + 1, y));
				}

				if (y >= 1 && grid[x][y - 1] == 1)
				{
					grid[x][y - 1] = 2;
					que.emplace(make_pair(x, y - 1));
				}

				if (y < m - 1 && grid[x][y + 1] == 1)
				{
					grid[x][y + 1] = 2;
					que.emplace(make_pair(x, y + 1));
				}
			}

			t++;
		} while (!que.empty());

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 1)
				{
					return -1;
				}
			}
		}

		return t - 1;
	}
};