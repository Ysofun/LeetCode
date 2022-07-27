#pragma once
#include <string>
using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        int mark = 0;
        for (unsigned int i = 0; i < astr.size(); i++)
        {
            int temp = 1 << (astr[i] - 'a');
            if (temp & mark) return false;
            mark += temp;
        }
        return true;
    }
};