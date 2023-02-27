#pragma once
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
	string maxSubString(string s)
	{
		int len = s.length();
		stack<char> maxChar;
		maxChar.push(s[len - 1]);
		for (int i = len - 2; i >= 0; i--)
		{
			maxChar.push(max(s[i], maxChar.top()));
		}

		string ans;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == maxChar.top()) { ans.push_back(s[i]); }
			maxChar.pop();
		}

		return ans;
	}
};