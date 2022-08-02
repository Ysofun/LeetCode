#pragma once



class Solution {
public:

	string temp;

	void FindAns(vector<string>& ans, int n, int LCnt, int RCnt)
	{
		if (temp.length() == n * 2)
		{
			ans.emplace_back(temp);
			return;
		}
		if (LCnt == 0)
		{
			temp += '(';
			FindAns(ans, n, LCnt + 1, RCnt);
			temp.pop_back();
			return;
		}

		if (LCnt == n)
		{
			temp += ')';
			FindAns(ans, n, LCnt, RCnt + 1);
			temp.pop_back();
			return;
		}

		temp += '(';
		FindAns(ans, n, LCnt + 1, RCnt);
		temp.pop_back();

		if (RCnt < LCnt)
		{
			temp += ')';
			FindAns(ans, n, LCnt, RCnt + 1);
			temp.pop_back();
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		FindAns(ans, n, 0, 0);

		return ans;
	}
};