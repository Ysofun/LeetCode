#pragma once
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string str;
        for (auto& ch : s)
        {
            if (ch == ' ')
            {
                str.append("%20");
            }
            else
            {
                str += ch;
            }
        }
        return str;
    }
};