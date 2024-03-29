#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[r])
            {
                r = mid;
            }
            else if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else if (nums[mid] == nums[r])
            {
                r--;
            }
        }
        return nums[l];
    }
};