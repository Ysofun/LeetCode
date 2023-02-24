#pragma once
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) { return mid; }
            if (nums[mid] < target) { l = mid + 1; }
            else { r = mid - 1; }
        }
        
        return nums[l] < target ? l + 1 : l;
    }
};