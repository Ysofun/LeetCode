#pragma once



class Solution {
public:
	/*int longestPalindrome(vector<string>& words) {
		unordered_map<string, int> AppearWord;

		int ans = 0;
		for (string& word : words)
		{
			string temp = word;
			if (temp[0] == temp[1])
			{
				if (AppearWord.find(temp) != AppearWord.end())
				{
					if (AppearWord[temp] == 0)
					{
						AppearWord[word]++;
						continue;
					}
					ans += 4;
					AppearWord[temp]--;
				}
				else
				{
					AppearWord[word]++;
				}
				continue;
			}

			reverse(temp.begin(), temp.end());
			if (AppearWord.find(temp) != AppearWord.end())
			{
				if (AppearWord[temp] == 0)
				{
					AppearWord[word]++;
					continue;
				}
				ans += 4;
				AppearWord[temp]--;
			}
			else
			{
				AppearWord[word]++;
			}
		}

		bool flag = false;
		for (unordered_map<string, int>::iterator it = AppearWord.begin(); it != AppearWord.end(); ++it)
		{
			if (it->first[0] == it->first[1] && it->second > 0)
			{
				flag = true;
				break;
			}
		}

		return flag ? ans + 2 : ans;
	}*/

	int longestPalindrome(vector<string>& words)
	{
		unordered_map<string, int> AppearWord;
		for (string& word : words)
		{
			AppearWord[word]++;
		}

		int ans = 0;
		bool mid = false;
		for (const auto& [word, cnt] : AppearWord)
		{
			string rev = string(1, word[1]) + word[0];
			if (word == rev)
			{
				if (cnt % 2 == 1)
				{
					mid = true;
				}
				ans += 2 * (cnt / 2 * 2);
			}
			else if (word > rev)
			{
				ans += 4 * min(AppearWord[word], AppearWord[rev]);
			}
		}

		return mid ? ans + 2 : ans;
	}
};