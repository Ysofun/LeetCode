#pragma once



class Solution {
public:

	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		
		vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));

		dp[0][0] = nums1[0] == nums2[0];

		for (int i = 1; i < nums1.size(); i++)
		{
			dp[i][0] = nums1[i] == nums2[0] ? 1 : dp[i - 1][0];
		}
		for (int j = 1; j < nums2.size(); j++)
		{
			dp[0][j] = nums1[0] == nums2[j] ? 1 : dp[0][j - 1];
		}

		for (int i = 1; i < nums1.size(); i++)
		{
			for (int j = 1; j < nums2.size(); j++)
			{
				if (nums1[i] == nums2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}

				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
			}
		}

		return dp[nums1.size() - 1][nums2.size() - 1];
	}
};
