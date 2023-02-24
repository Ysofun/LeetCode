#pragma once
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1, l = 0, r = 0;
        while (r < nums.size())
        {
            if (nums[l] == nums[r]) { r++; }
            else
            {
                nums[idx++] = nums[r];
                l = r;
                r++;
            }
        }
        return idx;
    }
};