#pragma once
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) { return false; }

		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += nums[i];
		}
		if (sum % 2 == 1) { return false; }

		vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
		dp[0][0] = true;
		dp[0][nums[0]] = true;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= sum; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= nums[i]) { dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i]]; }
			}
		}

		return dp[n - 1][sum / 2];
	}
};