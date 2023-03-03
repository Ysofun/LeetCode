#pragma once
class Solution {
public:
	string longestPalindrome(string s) {
		string ans;
		int len = s.length();
		int maxLen = 0;
		for (int i = 0; i < len; i++)
		{
			int l = i, r = i;
			while (l >= 0 && r < len && s[l] == s[r]) { l--; r++; }
			l++; 
			r--;
			if (r - l + 1 > maxLen)
			{
				maxLen = r - l + 1;
				ans = s.substr(l, r - l + 1);
			}

			l = i, r = i + 1;
			while (l >= 0 && r < len && s[l] == s[r]) { l--; r++; }
			l++;
			r--;
			if (r - l + 1 > maxLen)
			{
				maxLen = r - l + 1;
				ans = s.substr(l, r - l + 1);
			}
		}
		return ans;
	}
};