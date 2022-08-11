#pragma once



class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		
		int n = matrix.size(), m = matrix[0].size();
		vector<int> ans;
		
		while (n > 0 && m > 0)
		{
			for (int j = 0; j < m; j++)
			{
				ans.emplace_back(matrix[0][j]);
			}

			vector<vector<int>> temp(m, vector<int>(n - 1));
			for (int i = 1; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					temp[m - 1 - j][i - 1] = matrix[i][j];
				}
			}

			n = temp.size();
			m = temp[0].size();

			for (int i = 0; i < temp.size(); i++)
			{
				for (int j = 0; j < temp[i].size(); j++)
				{
					cout << temp[i][j] << ' ';
				}
				cout << endl;
			}

			matrix.swap(temp);
			temp.clear();
		}

		return ans;
	}
};