#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    struct SegTree
    {
        int lSum, rSum, mSum, iSum;
    };

    SegTree PushUp(SegTree leftTree, SegTree rightTree)
    {
        int lSum = max(leftTree.lSum, leftTree.iSum + rightTree.lSum);
        int rSum = max(rightTree.rSum, rightTree.iSum + leftTree.rSum);
        int iSum = leftTree.iSum + rightTree.iSum;
        int mSum = max(leftTree.rSum + rightTree.lSum, max(leftTree.mSum, rightTree.mSum));
        return SegTree{ lSum, rSum, mSum, iSum };
    }

    SegTree GetSum(vector<int>& nums, int l, int r)
    {
        if (l == r)
        {
            return SegTree{ nums[l], nums[l], nums[l], nums[l] };
        }
        int mid = (l + r) >> 1;
        SegTree leftTree = GetSum(nums, l, mid);
        SegTree rightTree = GetSum(nums, mid + 1, r);
        return PushUp(leftTree, rightTree);
    }

    int maxSubArray(vector<int>& nums) {
        return GetSum(nums, 0, nums.size() - 1).mSum;
    }
};