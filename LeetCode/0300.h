#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    /*
    int lengthOfLIS(vector<int>& nums) {
        int Ans = 0;
        vector<int> maxLIS(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    maxLIS[i] = max(maxLIS[j] + 1, maxLIS[i]);
                }
            }
            Ans = max(Ans, maxLIS[i]);
        }
        return Ans;
    }
    */
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() == 0) return 0;
        int len = 1;
        vector<int> tails(nums.size() + 1, 0);
        tails[len] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > tails[len])
            {
                len++;
                tails[len] = nums[i];
            }
            else
            {
                int l = 1, r = len, pos = 0;
                while (l <= r)
                {
                    int m = (l + r) >> 1;
                    if (tails[m] >= nums[i])
                    {
                        r = m - 1;
                    }
                    else
                    {
                        pos = m;
                        l = m + 1;
                    }
                }
                tails[pos + 1] = nums[i];
            }
        }
        return len;
    }
};