#pragma once
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> charNum(300, 0);
        for (int i = 0; i < s.size(); i++)
        {
            charNum[s[i]]++;
        }
        bool flag = false;
        for (auto& num : charNum)
        {
            if (num % 2 == 1)
            {
                if (flag == true) return false;
                else flag = true;
            }
        }
        return true;
    }
};