#pragma once
class Solution {
public:
    bool QuickAdd(int x, int y, int z)
    {
        int res = 0, add = x;
        while (y)
        {
            if (y & 1)
            {
                if (res < z - add) { return false; }
                res += add;
            }
            if (y != 1)
            {
                if (add < z - add) { return false; }
                add += add;
            }
            y >>= 1;
        }

        return true;
    }

    int divide(int a, int b) {
        if (a == INT_MIN)
        {
            if (b == 1) { return INT_MIN; }
            if (b == -1) { return INT_MAX; }
        }
        else if (b == INT_MIN) { return a == INT_MIN ? 1 : 0; }
        else if (a == 0) { return 0; }

        bool bRev = false;
        if (a > 0)
        {
            a = -a;
            bRev = !bRev;
        }
        if (b > 0)
        {
            b = -b;
            bRev = !bRev;
        }

        vector<int> condidates = { b };
        while (condidates.back() >= a - condidates.back())
        {
            condidates.push_back(condidates.back() + condidates.back());
        }

        int ans = 0;
        for (int i = condidates.size() - 1; i >= 0; i--)
        {
            if (condidates[i] >= a)
            {
                ans += (1 << i);
                a -= condidates[i];
            }
        }

        return bRev ? -ans : ans;
    }
};