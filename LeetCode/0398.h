#pragma once
class Solution {
public:
    map<int, vector<int>> NumLocation;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            NumLocation[nums[i]].emplace_back(i);
        }
    }

    int pick(int target) {
        int n = NumLocation[target].size();
        int r = rand() % n;
        return NumLocation[target][r];
    }
};
