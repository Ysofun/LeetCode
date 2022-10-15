#pragma once


class Solution {
public:
	vector<int> pathInZigZagTree(int label) {
		int a = 0;
		int k = 0;
		while (k < label)
		{
			a++;
			k = pow(2, a) - 1;
		}

		vector<int> ans;
		ans.emplace_back(label);
		int loc = a % 2 == 0 ? pow(2, a) - label : label - pow(2, a - 1) + 1;
		for (int i = a - 1; i >= 1; i--)
		{
			loc = (loc + 1) / 2;
			int val = i % 2 == 0 ? pow(2, i) - loc : loc + pow(2, i - 1) - 1;
			ans.emplace_back(val);
			loc = i % 2 == 0 ? pow(2, i) - val : val - pow(2, i - 1) + 1;
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};