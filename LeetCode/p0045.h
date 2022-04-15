#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums)
        {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), [](string& x, string& y) {return x + y < y + x; });
        string s;
        for (string str : strs)
        {
            s.append(str);
        }
        return s;
    }
};