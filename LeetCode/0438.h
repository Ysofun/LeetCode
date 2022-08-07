#pragma once



class Solution 
{
public:

	vector<int> findAnagrams(string s, string p) 
	{
		vector<int> LettersOfWindow(26, 0);
		vector<int> LettersOfP(26, 0);

		for (const char& ch : p)
		{
			LettersOfP[ch - 'a']++;
		}

		vector<int> ans;
		for (int slow = 0, fast = 0; fast < s.size(); fast++)
		{
			char CurrLetter = s[fast] - 'a';
			LettersOfWindow[CurrLetter]++;
			while (LettersOfWindow[CurrLetter] > LettersOfP[CurrLetter])
			{
				LettersOfWindow[s[slow] - 'a']--;
				slow++;
			}

			if (fast - slow + 1 == p.size())
			{
				ans.emplace_back(slow);
			}
		}

		return ans;
	}
};