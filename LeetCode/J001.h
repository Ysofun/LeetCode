#pragma once
#include <algorithm>
class Solution {
public:
    int divide(int a, int b) {
        if (a == 0) return 0;
        bool flag = false;
        if ((a > 0 && b < 0) || (a < 0 && b > 0))
        {
            flag = true;
        }
        a = abs(a);
        b = flag ? -abs(b) : abs(b);
        int ans = 0;
        while (a >= b)
        {
            a -= b;
            ans++;
        }
        return flag ? -ans : ans;
    }
};