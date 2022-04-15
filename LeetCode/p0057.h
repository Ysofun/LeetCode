#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i != j)
        {
            int sum = nums.at(i) + nums.at(j);
            if (target == sum)
            {
                return { nums.at(i), nums.at(j) };
            }
            else if (target < sum)
            {
                --j;
            }
            else
            {
                ++i;
            }
        }
        return { -1, -1 };
    }
};