#pragma once
class Solution {
public:
    int numWays(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1, b = 2, c;
        for (int i = 3; i <= n; i++)
        {
            c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return c;
    }
};