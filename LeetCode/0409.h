#pragma once



class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> Cnt;
		for (int i = 0; i < s.length(); i++)
		{
			if (Cnt.find(s[i]) != Cnt.end())
			{
				Cnt[s[i]]++;
			}
			else
			{
				Cnt.insert(make_pair(s[i], 1));
			}
		}

		int ans = 0;
		bool bHaveOdd = false;
		for (unordered_map<char, int>::iterator it = Cnt.begin(); it != Cnt.end(); ++it)
		{
			if (it->second % 2 == 0)
			{
				ans += it->second;
			}
			else
			{
				ans += it->second - 1;
				bHaveOdd = true;
			}
		}

		return ans + (bHaveOdd ? 1 : 0);
	}
};