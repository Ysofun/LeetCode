#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftIndex = nums.size(), rightIndex = nums.size();
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] <= target)
            {
                l = mid + 1;
                rightIndex = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
                leftIndex = mid;
            }
        }
        if (leftIndex <= rightIndex && rightIndex < nums.size() && leftIndex >= 0 && nums[leftIndex] == target && nums[rightIndex] == target)
        {
            return rightIndex - leftIndex + 1;
        }
        return 0;
    }
};