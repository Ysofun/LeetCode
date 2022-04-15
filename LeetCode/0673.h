#pragma once
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int BinarySearch(int n, function<bool(int)> f)
    {
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (f(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> d, cnt;
        for (int num : nums)
        {
            int i = BinarySearch(d.size(), [&](int param) { return d[param].back() >= num; });
            int c = 1;
            if (i > 0)
            {
                int k = BinarySearch(d[i - 1].size(), [&](int param) { return d[i - 1][param] < num; });
                c = cnt[i - 1].back() - cnt[i - 1][k];
            }
            if (i == d.size())
            {
                d.push_back({ num });
                cnt.push_back({ 0, c });
            }
            else
            {
                d[i].push_back(num);
                cnt[i].push_back(cnt[i].back() + c);
            }
        }
        return cnt.back().back();
    }
};