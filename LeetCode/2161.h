#pragma once
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, pivot);
        int l = 0, r = n - 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                ans[l] = nums[i];
                l++;
            }
            if (nums[n - 1 - i] > pivot)
            {
                ans[r] = nums[n - 1 - i];
                r--;
            }
        }
        
        return ans;
    }
};