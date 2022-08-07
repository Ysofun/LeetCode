#pragma once



class Solution {
public:
	/*int characterReplacement(string s, int k) {

		int ans = 0;
		for (int i = 0; i < 26; i++)
		{
			char CurrLetter = i + 'A';
			int slow = 0;
			int TempK = k;
			for (int fast = 0; fast < s.size(); fast++)
			{
				if (s[fast] != CurrLetter)
				{
					if (TempK == 0)
					{
						ans = max(ans, fast - slow);
						while (s[slow] == CurrLetter)
						{
							slow++;
						}
						slow++;
					}
					else
					{
						TempK--;
					}
				}
			}

			ans = max(ans, (int)s.size() - slow);
		}

		return ans;
	}*/

	int characterReplacement(string s, int k)
	{
		vector<int> LettersOfWindow(26, 0);

		int len = s.size();
		int maxn = 0;
		int slow = 0, fast = 0;
		while (fast < s.size())
		{
			LettersOfWindow[s[fast] - 'A']++;
			maxn = max(maxn, LettersOfWindow[s[fast] - 'A']);
			if (fast - slow + 1 - maxn > k)
			{
				LettersOfWindow[s[slow] - 'A']--;
				slow++;
			}
			fast++;
		}

		return fast - slow;
	}
};