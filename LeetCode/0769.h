#pragma once


class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		int ans = 0, maxn = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			maxn = max(maxn, arr[i]);
			if (maxn == i) { ans++; }
		}
		return ans;
	}
};