#pragma once


class Solution {
public:

	vector<int> val;
	vector<vector<int>> res;

	int QueryCoins(int left, int right)
	{
		if (left >= right - 1) { return 0; }
		if (res[left][right] != -1) { return res[left][right]; }

		for (int i = left + 1; i < right; i++)
		{
			int sum = val[i] * val[left] * val[right];
			sum += QueryCoins(left, i) + QueryCoins(i, right);
			res[left][right] = max(res[left][right], sum);
		}

		return res[left][right];
	}

	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		val.resize(n + 2);
		res.resize(n + 2, vector<int>(n + 2, -1));
		for (int i = 1; i <= n; i++)
		{
			val[i] = nums[i - 1];
		}

		val[0] = val[n + 1] = 1;
		return QueryCoins(0, n + 1);
	}
};