#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 3) return max(max(nums[0], nums[1]), nums[2]);
        int a, b, c, d, ans = 0;

        a = nums[0], b = nums[1], c = max(a + nums[2], b), d = 0;
        for (int i = 3; i < nums.size() - 1; i++)
        {
            d = max(max(a + nums[i], b + nums[i]), c);
            a = b;
            b = c;
            c = d;
        }
        ans = max(max(ans, c), d);

        a = nums[1], b = nums[2], c = max(a + nums[3], b), d = 0;
        for (int i = 4; i < nums.size(); i++)
        {
            d = max(max(a + nums[i], b + nums[i]), c);
            a = b;
            b = c;
            c = d;
        }
        ans = max(max(ans, c), d);
        return ans;
    }
};