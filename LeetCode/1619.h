#pragma once


class Solution {
public:
	double trimMean(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int n = arr.size();
		int len = n * 0.05;
		double ans = 0;
		for (int i = len; i < n - len; i++)
		{
			ans += arr[i];
		}

		return ans / (n - 2 * len);
	}
};