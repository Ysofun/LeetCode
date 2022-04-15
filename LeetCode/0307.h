#pragma once
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> SegTree;
    int n;
public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->SegTree.resize(n << 2, 0);
        if (n > 0)
        {
            Build(0, n - 1, 1, nums);
        }
    }

    void PushUp(int root)
    {
        SegTree[root] = SegTree[root << 1] + SegTree[root << 1 | 1];
    }

    void Build(int left, int right, int root, vector<int>& nums)
    {
        if (left == right)
        {
            SegTree[root] = nums[left];
            return;
        }

        int mid = (left + right) >> 1;
        Build(left, mid, root << 1, nums);
        Build(mid + 1, right, root << 1 | 1, nums);
        PushUp(root);
    }

    void update(int index, int val, int left, int right, int root)
    {
        if (left == right)
        {
            SegTree[root] = val;
            return;
        }

        int mid = (left + right) >> 1;
        if (index <= mid) update(index, val, left, mid, root << 1);
        else update(index, val, mid + 1, right, root << 1 | 1);
        PushUp(root);
    }

    void update(int index, int val) {
        update(index, val, 0, n - 1, 1);
    }

    int sumRange(int Left, int Right, int left, int right, int root)
    {
        if (Left <= left && right <= Right)
        {
            return SegTree[root];
        }

        int ret = 0;
        int mid = (left + right) >> 1;
        if (Left <= mid) ret += sumRange(Left, Right, left, mid, root << 1);
        if (Right > mid) ret += sumRange(Left, Right, mid + 1, right, root << 1 | 1);
        return ret;
    }

    int sumRange(int left, int right) {
        return sumRange(left, right, 0, n - 1, 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */