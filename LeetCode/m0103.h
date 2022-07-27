#pragma once
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int len = S.size() - 1;
        for (int i = length - 1; i >= 0; i--)
        {
            if (S[i] == ' ')
            {
                S[len--] = '0';
                S[len--] = '2';
                S[len--] = '%';
            }
            else
            {
                S[len--] = S[i];
            }
        }
        return S.substr(len + 1);
    }
};