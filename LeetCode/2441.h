#pragma once

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool> fu(1001, false);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                fu[-nums[i]] = true;
            }
        }

        int ans = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > ans && fu[nums[i]])
            {
                ans = nums[i];
            }
        }

        return ans;
    }
};