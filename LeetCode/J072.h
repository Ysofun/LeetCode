#pragma once
class Solution {
public:
    int mySqrt(int x) {
        long long s = x;
        while (s * s > x) { s = (s + x / s) / 2; }
        return s;
    }
};