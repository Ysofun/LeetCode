#pragma once
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> AppearLocation(128, -1);
        int l = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            l = max(l, AppearLocation[s[i]] + 1);
            ans = max(ans, i - l + 1);
            AppearLocation[s[i]] = i;
        }
        return ans;
    }
};