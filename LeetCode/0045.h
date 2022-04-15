#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0, range = 0, end = 0, n = nums.size() - 1;
        for (int i = 0; i < n; i++)
        {
            if (i <= end) range = max(range, i + nums[i]);
            if (i == end)
            {
                cnt++;
                end = range;
            }
        }
        return cnt;
    }
};