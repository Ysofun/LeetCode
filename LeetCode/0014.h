#pragma once



class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string temp = strs[0];

		for (int i = 0; i < strs.size(); i++)
		{
			if (temp.empty())
			{
				break;
			}

			int j = 0;
			string& str = strs[i];
			while (j < temp.size() && j < str.size() && temp[j] == str[j])
			{
				j++;
			}
			temp = temp.substr(0, j);
		}

		return temp;
	}

};