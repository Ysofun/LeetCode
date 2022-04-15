#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    /*
    int majorityElement(vector<int>& nums) {
        return majorityElementDAC(nums, 0, nums.size() - 1);
    }

    int majorityElementDAC(vector<int>& nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right) / 2;
        int leftMajority = majorityElementDAC(nums, left, mid);
        int rightMajority = majorityElementDAC(nums, mid + 1, right);
        if (CountNumber(nums, left, right, leftMajority) > (right - left + 1) / 2)
        {
            return leftMajority;
        }
        if (CountNumber(nums, left, right, rightMajority) > (right - left + 1) / 2)
        {
            return rightMajority;
        }
        return -1;
        
    }

    int CountNumber(vector<int>& nums, int left, int right, int num)
    {
        int count = 0;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] == num)
            {
                count++;
            }
        }
        return count;
    }
    */
    int majorityElement(vector<int>& nums)
    {
        int candidate = nums[0];
        int count = 0;
        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }
            if (candidate == num)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};