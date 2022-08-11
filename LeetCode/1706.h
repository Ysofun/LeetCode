#pragma once



class Solution {
public:
	vector<int> findBall(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();

		vector<int> ans;
		for (int k = 0; k < m; k++)
		{
			int j = k;
			for (int i = 0; i < n; i++)
			{
				int dir = grid[i][j];
				j += dir;
				if (j < 0 || j == m || grid[i][j] != dir)
				{
					j = -1;
					break;
				}
			}
			ans.emplace_back(j);
		}

		return ans;
	}
};