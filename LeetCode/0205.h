#pragma once



class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.length() != t.length())
		{
			return false;
		}

		map<char, char> charFunction;
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			if (charFunction.find(s[i]) != charFunction.end())
			{
				if (charFunction[s[i]] != t[i])
				{
					return false;
				}
			}
			else
			{
				charFunction.insert(make_pair(s[i], t[i]));
			}
		}

		charFunction.clear();
		for (int i = 0; i < len; i++)
		{
			if (charFunction.find(t[i]) != charFunction.end())
			{
				if (charFunction[t[i]] != s[i])
				{
					return false;
				}
			}
			else
			{
				charFunction.insert(make_pair(t[i], s[i]));
			}
		}

		return true;
	}
};