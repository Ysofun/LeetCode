#pragma once
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> AppearChar(128);
        int ans = 0, l = 0;
        for (int r = 0; r < s.size(); r++)
        {
            l = max(l, AppearChar[s[r]]);
            ans = max(r - l + 1, ans);
            AppearChar[s[r]] = r + 1;
        }
        return ans;
    }
};