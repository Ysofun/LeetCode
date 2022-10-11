#pragma once


class Solution {
public:
	bool areAlmostEqual(string s1, string s2) {
		int len1 = s1.size(), len2 = s2.size();
		if (len1 != len2) { return false; }

		int diff = 0, idx = 0;
		for (int i = 0; i < len1; i++)
		{
			if (s1[i] != s2[i])
			{
				diff++;
				if (diff == 2)
				{
					if (s1[i] != s2[idx] || s1[idx] != s2[i]) 
					{ 
						return false; 
					}
				}
				else if (diff > 2)
				{
					return false;
				}
				idx = i;
			}
		}

		return diff != 1;
	}
};