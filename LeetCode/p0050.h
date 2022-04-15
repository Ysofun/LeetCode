#pragma once
#include <string>
using namespace std;

class Solution {
private:
    int charAppear[26];
public:
    char firstUniqChar(string s) {
        for (auto& ch : s)
        {
            charAppear[ch - 'a']++;
        }
        for (auto& ch : s)
        {
            if (charAppear[ch - 'a'] == 1)
            {
                return ch;
            }
        }
        return ' ';
    }
};