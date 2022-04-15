#pragma once

class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        long z = 0;
        while (x > 0)
        {
            int temp = x % 10;
            z = z * 10 + (long)temp;
            x = x / 10;
        }
        return (long)y == z;
    }
};