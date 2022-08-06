#pragma once



class Solution {
public:
	int balancedStringSplit(string s) {
		
		int ans = 0, l = 0;

		for (int i = 0; i < s.length(); i++)
		{
			l = s[i] == 'L' ? l + 1 : l - 1;
			if (l == 0)
			{
				ans++;
			}
		}

		return ans;
	}
};