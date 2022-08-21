#pragma once
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class Solution {
private:
	int dir_x[4] = { 0, -1, 0, 1 };
	int dir_y[4] = { -1, 0, 1, 0 };
	int n, m;

public:

	void DFS(vector<vector<int>>& heights, vector<vector<bool>>& Ocean, int i, int j)
	{
		if (Ocean[i][j]) { return; }
		
		Ocean[i][j] = true;
		for (int k = 0; k < 4; k++)
		{
			int x = i + dir_x[k];
			int y = j + dir_y[k];

			if (x >= 0 && x < n && y >= 0 && y < m && heights[x][y] >= heights[i][j]) { DFS(heights, Ocean, x, y); }
		}
	}

	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		n = heights.size(), m = heights[0].size();

		vector<vector<bool>> Pacific(n, vector<bool>(m, false));
		vector<vector<bool>> Atlantic(n, vector<bool>(m, false));

		for (int j = 0; j < m; j++) { DFS(heights, Pacific, 0, j); }
		for (int i = 0; i < n; i++) { DFS(heights, Pacific, i, 0); }

		for (int j = 0; j < m; j++) { DFS(heights, Atlantic, n - 1, j); }
		for (int i = 0; i < n; i++) { DFS(heights, Atlantic, i, m - 1); }

		vector<vector<int>> ans;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (Pacific[i][j] && Atlantic[i][j])
				{
					ans.emplace_back((vector<int>) { i, j });
				}
			}
		}

		return ans;
	}
};