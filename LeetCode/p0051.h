#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int ans = 0;
    void MergeSort(vector<int>& nums, int l, int r)
    {
        if (l < r)
        {
            int mid = (l + r) >> 1;
            MergeSort(nums, l, mid);
            MergeSort(nums, mid + 1, r);
            Merge(nums, l, r);
        }
    }

    void Merge(vector<int>& nums, int l, int r)
    {
        vector<int> temp;
        int mid = (l + r) >> 1;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r)
        {
            if (nums[i] <= nums[j])
            {
                temp.push_back(nums[i]);
                i++;
                ans += j - mid - 1;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
            ans += j - mid - 1;
        }
        while (j <= r)
        {
            temp.push_back(nums[j]);
            j++;
        }
        for (i = l; i <= r; i++)
        {
            nums[i] = temp[i - l];
        }
    }

    int reversePairs(vector<int>& nums) {
        MergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};