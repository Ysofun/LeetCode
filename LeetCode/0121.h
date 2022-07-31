#pragma once



class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ans = 0;
		int MinPrices = 0x7fffffff;
		for (int i = 0; i < prices.size(); i++)
		{
			ans = max(ans, prices[i] - MinPrices);
			MinPrices = min(MinPrices, prices[i]);
		}

		return ans;
	}
};