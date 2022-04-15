#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = numsMap.find(target - nums[i]);
            if (it != numsMap.end())
            {
                return { it->second, i };
            }
            numsMap[nums[i]] = i;
        }
        return {};
    }
};