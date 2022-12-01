#pragma once
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0, n = nums.size();
		for (int i = 0; i < n; i++)
		{
			sum += nums[i];
		}
		
		int diff = sum - target;
		if (diff < 0 || diff % 2 != 0) { return 0; }

		int neg = diff / 2;
		vector<vector<int>> Dp(n + 1, vector<int>(neg + 1));
		Dp[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			int num = nums[i - 1];
			for (int j = 0; j <= neg; j++)
			{
				Dp[i][j] = Dp[i - 1][j];
				if (j >= num) { Dp[i][j] += Dp[i - 1][j - num]; }
			}
		}

		return Dp[n][neg];
	}
};