#pragma once



class Solution {
public:

	struct CmpByValue
	{
		bool operator()(const pair<string, int>& x, const pair<string, int>& y) const
		{
			return x.second == y.second ? x.first < y.first : x.second > y.second;
		}
	};

	vector<string> topKFrequent(vector<string>& words, int k) {
		
		unordered_map<string, int> LetterTimes;
		for (const string& word : words)
		{
			LetterTimes[word]++;
		}

		vector<pair<string, int>> vec(LetterTimes.begin(), LetterTimes.end());
		sort(vec.begin(), vec.end(), CmpByValue());

		vector<string> ans;
		for (int i = 0; i < k; i++)
		{
			ans.emplace_back(vec[i].first);
		}

		return ans;
	}
};