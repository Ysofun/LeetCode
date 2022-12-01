#pragma once
class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(vector<vector<int>>(m + 1, vector<int>(n + 1)));
		int ans = 0;
		for (int i = 0; i < strs.size(); i++)
		{
			int zero = 0;
			int one = 0;
			for (int j = 0; j < strs[i].size(); j++)
			{
				if (strs[i][j] == '0') { zero++; }
				else { one++; }
			}
			for (int j = m; j >= zero; j--)
			{
				for (int k = n; k >= one; k--)
				{
					dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1); 
					ans = max(ans, dp[j][k]);
				}
			}
		}

		return ans;
	}
};