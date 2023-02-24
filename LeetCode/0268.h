#pragma once
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		nums.push_back(-1);
		for (int i = 0; i < n; i++)
		{
			nums[nums[i] % (2 * n)] += 2 * n;
		}

		for (int i = 0; i <= n; i++)
		{
			if (nums[i] <= n) { return i; }
		}

		return n;
	}
};