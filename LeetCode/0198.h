#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = max(nums[2] + dp[0], dp[1]);
        for (int i = 3; i < nums.size(); i++)
        {
            dp[i] = max(max(nums[i] + dp[i - 2], dp[i - 1]), dp[i - 3] + nums[i]);
        }
        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};