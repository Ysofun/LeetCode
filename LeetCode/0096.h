#pragma once
class Solution {
public:
    int numTrees(int n) {
        int f[20];
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = 0;
            for (int j = 1; j <= i; j++)
            {
                f[i] += f[i - j] * f[j - 1];
            }
        }
        return f[n];
    }
};