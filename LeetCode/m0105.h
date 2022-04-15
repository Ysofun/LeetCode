#pragma once
#include <cmath>
#include <string>
using namespace std;
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (abs((int)first.size() - (int)second.size()) > 1) return false;
        int i = 0, j = 0;
        int n = first.length(), m = second.length();
        if (n == m)
        {
            int cnt = 0;
            while (i < n && j < m)
            {
                if (first[i] != second[j]) cnt++;
                i++;
                j++;
            }
            if (cnt <= 1) return true;
            else return false;
        }
        else if (n < m)
        {
            int cnt = 0;
            while (i < n && j < m)
            {
                if (first[i] != second[j])
                {
                    cnt++;
                    j++;
                    continue;
                }
                i++;
                j++;
            }
            if (cnt <= 1) return true;
            else return false;
        }
        else
        {
            int cnt = 0;
            while (i < n && j < m)
            {
                if (first[i] != second[j])
                {
                    cnt++;
                    i++;
                    continue;
                }
                i++;
                j++;
            }
            if (cnt <= 1) return true;
            else return false;
        }
    }
};