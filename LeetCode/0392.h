#pragma once



class Solution {
public:
	bool isSubsequence(string s, string t) {
		
		if (s.empty())
		{
			return true;
		}

		for (int i = 0; i < t.length(); i++)
		{
			if (s[0] == t[i])
			{
				int j = 0, k = i;
				while (j < s.length() && k < t.length())
				{
					if (s[j] == t[k])
					{
						j++;
					}
					k++;
				}
				if (j == s.length())
				{
					return true;
				}
			}
		}
		return false;
	}
};