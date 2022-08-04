#pragma once



class Solution {
public:

	void FillIsland(vector<vector<char>>& grid, int x, int y)
	{
		if (grid[x][y] == '0')
		{
			return;
		}

		grid[x][y] = '0';

		if (x - 1 >= 0 && grid[x - 1][y] == '1')
		{
			FillIsland(grid, x - 1, y);
		}

		if (x + 1 < grid.size() && grid[x + 1][y] == '1')
		{
			FillIsland(grid, x + 1, y);
		}

		if (y - 1 >= 0 && grid[x][y - 1] == '1')
		{
			FillIsland(grid, x, y - 1);
		}

		if (y + 1 < grid[0].size() && grid[x][y + 1] == '1')
		{
			FillIsland(grid, x, y + 1);
		}
	}

	int numIslands(vector<vector<char>>& grid) {

		int ans = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					ans++;
					FillIsland(grid, i, j);
				}
			}
		}

		return ans;
	}
};