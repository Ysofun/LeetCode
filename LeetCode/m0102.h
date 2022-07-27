#pragma once
#include <string>
using namespace std;

class Solution {
private:
    int sum1[30], sum2[30];
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int len = s1.length();
        for (unsigned int i = 0; i < len; i++)
        {
            sum1[s1[i] - 'a']++;
            sum2[s2[i] - 'a']++;
        }

        for (unsigned int i = 0; i < 26; i++)
        {
            if (sum1[i] != sum2[i]) return false;
        }
        return true;
    }
};