#pragma once
class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        auto cmp = [](const vector<int>& x, const vector<int>& y)
        {
            return x[2] > y[2];
        };

        sort(box.begin(), box.end(), cmp);

        int n = box.size(), ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = box[i][2];
            for (int j = 0; j < i; j++)
            {
                if (box[i][0] < box[j][0] && box[i][1] < box[j][1] && box[i][2] < box[j][2])
                {
                    dp[i] = max(dp[i], box[i][2] + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};