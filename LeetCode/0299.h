#pragma once



class Solution {
public:
	string getHint(string secret, string guess) {
		vector<int> nums(10);

		for (int i = 0; i < secret.size(); i++)
		{
			nums[secret[i] - '0']++;
		}

		int bulls = 0, cows = 0;
		for (int i = 0; i < guess.size(); i++)
		{
			if (secret[i] == guess[i])
			{
				bulls++;
				nums[secret[i] - '0']--;
			}
		}

		for (int i = 0; i < guess.size(); i++)
		{
			if (secret[i] != guess[i] && nums[guess[i] - '0'] > 0)
			{
				cows++;
				nums[guess[i] - '0']--;
			}
		}

		return to_string(bulls) + 'A' + to_string(cows) + 'B';
	}
};