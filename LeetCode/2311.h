#pragma once
class Solution {
public:
	int longestSubsequence(string s, int k) {
		int mul = 2, len = s.size(), del = 0;
		vector<int> Val(len, 0);
		Val[len - 1] = s[len - 1] - '0';
		for (int i = len - 2; i >= 0; i--)
		{
			Val[i] = s[i] == '0' ? Val[i + 1] : Val[i + 1] + mul;
			if (Val[i] > k)
			{
				for (int j = i; j >= 0; j--)
				{
					if (s[j] == '1')
					{
						s[j] = '0';
						del++;
						Val[j] = Val[j + 1];
					}
				}

				break;
			}
			
			mul *= 2;
			if (mul >= 1000000000)
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (s[j] == '1')
					{
						s[j] = '0';
						del++;
						Val[j] = Val[j + 1];
					}
				}

				break;
			}
		}

		return s.size() - del;
	}
};