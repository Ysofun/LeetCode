#pragma once
class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		int sum = accumulate(stones.begin(), stones.end(), 0);
		int n = stones.size(), m = sum / 2;
		if (n == 1) { return sum; }

		vector<vector<bool>> dp(n, vector<bool>(m + 1));
		dp[0][0] = dp[0][stones[0]] = true;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= stones[i]) { dp[i][j] = dp[i][j] || dp[i - 1][j - stones[i]]; }
			}
		}

		for (int j = m; j >= 0; j--)
		{
			if (dp[n - 1][j]) { return sum - 2 * j; }
		}

		return -1;
	}
};