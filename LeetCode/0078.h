#pragma once
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& now, int i)
    {
        if (i >= nums.size())
        {
            ans.push_back(now);
            return;
        }
        
        now.push_back(nums[i]);
        dfs(nums, ans, now, i + 1);
        now.pop_back();

        dfs(nums, ans, now, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> now;
        dfs(nums, ans, now, 0);
        return ans;
    }
};