#pragma once
class Solution {
public:
    int fib(int n) {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++)
        {
            c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return c;
    }
};