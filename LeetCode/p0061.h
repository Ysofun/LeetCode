#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int joker = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                joker++;
                continue;
            }
            if (i == 0 || nums[i - 1] == 0) continue;
            else if (nums[i] == nums[i - 1]) return false;
            else if (nums[i] > nums[i - 1] + 1)
            {
                if (joker < nums[i] - nums[i - 1] - 1) return false;
                else joker -= nums[i] - nums[i - 1] - 1;
            }
        }
        return true;
    }
};