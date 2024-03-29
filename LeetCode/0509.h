#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    /*
    int fib(int n) {
        vector<int> fib;
        fib.push_back(0);
        fib.push_back(1);
        for (int i = 2; i <= n; i++)
        {
            int temp = fib[i - 1] + fib[i - 2];
            fib.push_back(temp);
        }
        return fib[n];
    }
    */
    int fib(int n)
    {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};