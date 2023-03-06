#pragma once
class Solution {
public:
	string addStrings(string num1, string num2) {
		string ans;
		int p1 = num1.size() - 1, p2 = num2.size() - 1;
		int num = 0;
		while (p1 >= 0 && p2 >= 0)
		{
			num += num1[p1] - '0' + num2[p2] - '0';
			ans.push_back(num % 10 + '0');
			num /= 10;
			p1--;
			p2--;
		}

		while (p1 >= 0) 
		{ 
			num += num1[p1--] - '0';
			ans.push_back(num % 10 + '0');
			num /= 10;
		}
		while (p2 >= 0)
		{
			num += num2[p2--] - '0';
			ans.push_back(num % 10 + '0');
			num /= 10;
		}

		if (num == 1) { ans.push_back('1'); }
		reverse(ans.begin(), ans.end());
		return ans;
	}
};