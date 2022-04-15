#pragma once
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	struct TrieNode
	{
		bool isEnd;
		TrieNode* child[26];
		TrieNode()
		{
			this->isEnd = false;
			for (int i = 0; i < 26; i++)
			{
				child[i] = nullptr;
			}
		}
	};
	TrieNode* root;
	vector<bool> failFlag;

    bool wordBreak(string s, vector<string>& wordDict) {
		root = new TrieNode();
		failFlag.resize(300, false);
		for (auto& word : wordDict)
		{
			TrieNode* p = root;
			for (auto& ch : word)
			{
				if (p->child[ch - 'a'] == nullptr)
				{
					p->child[ch - 'a'] = new TrieNode();
				}
				p = p->child[ch - 'a'];
			}
			p->isEnd = true;
		}
		return SearchTrie(s, 0);
    }

	bool SearchTrie(string& s, int start)
	{
		if (failFlag[start] == true)
		{
			return false;
		}
		if (start == s.size())
		{
			return true;
		}

		TrieNode* p = root;
		for (int i = start; i < s.size(); i++)
		{
			if (p->child[s[i] - 'a'] != nullptr)
			{
				p = p->child[s[i] - 'a'];
				if (p->isEnd && SearchTrie(s, i + 1))
				{
					return true;
				}
			}
			else
			{
				break;
			}
		}
		failFlag[start] = true;
		return false;
	}
};