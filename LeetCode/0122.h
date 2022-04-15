    #pragma once
    #include <vector>
    using namespace std;

    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.size() == 1) return 0;
            int boughtShare = -1, ans = 0;
            int n = prices.size();
            for (int i = 0; i < n; i++)
            {
                if (i == 0 && prices[i + 1] > prices[i])
                {
                    boughtShare = prices[i];
                }
                else if (i == n - 1 && boughtShare != -1)
                {
                    ans += prices[i] - boughtShare;
                }
                else if (i != 0 && i != n - 1 && prices[i] <= prices[i - 1] && prices[i] < prices[i + 1]) 
                {
                    boughtShare = prices[i];
                }
                else if (i != 0 && i != n - 1 && prices[i] > prices[i - 1] && prices[i] >= prices[i + 1])
                {
                    ans += prices[i] - boughtShare;
                    boughtShare = -1;
                }
            }
            return ans;
        }
    };