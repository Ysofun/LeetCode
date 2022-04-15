#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = nums[0], maxSum = nums[0], curMax = nums[0], minSum = nums[0], curMin = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            total += nums[i];
            curMax = max(curMax + nums[i], nums[i]);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + nums[i], nums[i]);
            minSum = min(minSum, curMin);
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};