#pragma once
class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();

		if (n * m == 0) { return n + m; }

		vector<vector<int>> dp(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= m; i++) { dp[0][i] = i; }
		for (int i = 0; i <= n; i++) { dp[i][0] = i; }

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int left = dp[i - 1][j] + 1;
				int right = dp[i][j - 1] + 1;
				int together = dp[i - 1][j - 1];
				if (word1[i - 1] != word2[j - 1]) { together++; }

				dp[i][j] = min(left, min(right, together));
			}
		}

		return dp[n][m];
	}
};