#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> vals(10001, 0);
        for (auto& num : nums)
        {
            vals[num] += num;
        }
        int a = vals[0], b = vals[1], c = max(a + vals[2], b), d = 0;
        for (int i = 3; i < vals.size(); i++)
        {
            d = max(max(a + vals[i], b + vals[i]), c);
            a = b;
            b = c;
            c = d;
        }
        return max(c, d);
    }
};