#pragma once


//class Solution {
//public:
//	int longestValidParentheses(string s) {
//		stack<pair<char, int>> leftK;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == '(') { leftK.push(pair<char, int>(s[i], i)); }
//			if (s[i] == ')')
//			{
//				if (!leftK.empty())
//				{
//					int idx = leftK.top().second;
//					leftK.pop();
//					s[idx] = '0';
//					s[i] = '0';
//				}
//			}
//		}
//
//		int ans = 0, sum = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == '0') { sum++; }
//			else
//			{
//				ans = max(ans, sum);
//				sum = 0;
//			}
//		}
//
//		return max(ans, sum);
//	}
//};

class Solution {
public:
	int longestValidParentheses(string s) {
		int ans = 0;
		int len = s.size();
		vector<int> dp(len);
		for (int i = 1; i < len; i++)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(') 
				{ 
					if (i - 2 >= 0) { dp[i] = dp[i - 2] + 2; }
					else { dp[i] = 2; }
				}
				else
				{
					if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
					{
						if (i - dp[i - 1] - 2 >= 0)
							dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
						else
							dp[i] = dp[i - 1] + 2;
					}
				}
			}
			ans = max(ans, dp[i]);
		}

		return ans;
	}
};