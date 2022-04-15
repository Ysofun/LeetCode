#pragma once
#include <string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string str;
        for (int i = n; i < s.length(); i++)
        {
            str += s[i];
        }
        for (int i = 0; i < n; i++)
        {
            str += s[i];
        }
        return str;
    }
};