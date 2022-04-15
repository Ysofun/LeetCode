#pragma once
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int sum = 0;
        map<char, int> chPos;
        for (int i = 0; i < s.length(); i++)
        {
            if (chPos.find(s[i]) == chPos.end())
            {
                sum++;
                chPos.insert(pair<char, int>(s[i], i));
            }
            else
            {
                ans = max(ans, sum);
                sum = i - chPos[s[i]];
                for (auto iter = chPos.begin(); iter != chPos.end();)
                {
                    if (iter->second < chPos[s[i]])
                    {
                        chPos.erase(iter++);
                    }
                    else
                    {
                        iter++;
                    }
                }
                chPos[s[i]] = i;
            }
        }
        return max(ans, sum);
    }
};