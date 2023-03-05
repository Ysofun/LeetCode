#pragma once



class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int xGo[4] = { 0, 1, 0, -1 };
		int yGo[4] = { 1, 0, -1, 0 };

		int n = matrix.size(), m = matrix[0].size();
		vector<vector<bool>> bWalked(n, vector<bool>(m, false));
		vector<int> ans;
		int direction = 0, x = 0, y = 0;
		ans.emplace_back(matrix[0][0]);
		bWalked[0][0] = true;
		while (ans.size() < n * m)
		{
			int nextX = x + xGo[direction % 4];
			int nextY = y + yGo[direction % 4];

			if (nextX < 0 || nextY < 0 || nextX == n || nextY == m || bWalked[nextX][nextY])
			{
				direction++;
				continue;
			}
			ans.emplace_back(matrix[nextX][nextY]);
			bWalked[nextX][nextY] = true;
			x = nextX;
			y = nextY;
		}

		return ans;
	}
};