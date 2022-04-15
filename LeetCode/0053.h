#pragma once
#include <vector>
using namespace std;

class Solution {
private:
    int sum[40000];
public:
    /*
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxSum = nums[0];
        for (int num : nums)
        {
            pre = max(pre + num, num);
            maxSum = max(pre, maxSum);
        }
        return maxSum;
    }
    */
    struct SumTree
    {
        int lSum, rSum, iSum, mSum;
        SumTree(int lSum, int rSum, int iSum, int mSum)
        {
            this->lSum = lSum;
            this->rSum = rSum;
            this->iSum = iSum;
            this->mSum = mSum;
        }
    };

    int maxSubArray(vector<int>& nums)
    {
        return Query(nums, 0, nums.size() - 1).mSum;
    }

    SumTree PushUp(SumTree leftTree, SumTree rightTree)
    {
        int iSum = leftTree.iSum + rightTree.iSum;
        int lSum = max(leftTree.lSum, leftTree.iSum + rightTree.lSum);
        int rSum = max(rightTree.rSum, rightTree.iSum + leftTree.rSum);
        int mSum = max(max(leftTree.mSum, rightTree.mSum), leftTree.rSum + rightTree.lSum);
        return SumTree(lSum, rSum, iSum, mSum);
    }

    SumTree Query(vector<int>& nums, int left, int right)
    {
        if (left == right)
        {
            return SumTree(nums[left], nums[left], nums[left], nums[left]);
        }
        int mid = (left + right) >> 1;
        SumTree leftTree = Query(nums, left, mid);
        SumTree rightTree = Query(nums, mid + 1, right);
        return PushUp(leftTree, rightTree);
    }
};