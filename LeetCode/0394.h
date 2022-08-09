#pragma once
#include <string>
using namespace std;


class Solution {
public:
	/*string decodeString(string s) {

		stack<char> letters;
		stack<int> nums;

		int l = 0, r = 0;
		string t;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				int num = 0;
				while (s[i] >= '0' && s[i] <= '9')
				{
					num = num * 10 + s[i] - '0';
					i++;
				}

				i--;
				nums.push(num);
			}
			else
			{
				if (s[i] == '[')
				{
					l++;
					letters.push(s[i]);
				}
				else if (s[i] == ']')
				{
					r++;
					string temp;
					while (!letters.empty() && letters.top() != '[')
					{
						temp += letters.top();
						letters.pop();
					}

					letters.pop();
					reverse(temp.begin(), temp.end());

					if (l == r)
					{
						for (int j = 0; j < nums.top(); j++)
						{
							t.append(temp);
						}
					}
					else
					{
						for (int j = 0; j < nums.top(); j++)
						{
							for (int k = 0; k < temp.size(); k++)
							{
								letters.push(temp[k]);
							}
						}
						nums.pop();
					}
				}
				else
				{
					if (l == r)
					{
						t += s[i];
					}
					else
					{
						letters.push(s[i]);
					}
				}
			}
		}

		return t;
	}*/

	pair<int, string> decodeString(const string& s, int l, int k)
	{
		string temp;
		int i = l;

		while (i < s.size() && s[i] != ']')
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				int num = 0;
				while (s[i] >= '0' && s[i] <= '9')
				{
					num = num * 10 + s[i] - '0';
					i++;
				}

				pair<int, string> ret = decodeString(s, i + 1, num);
				i = ret.first;
				temp.append(ret.second);
			}
			else
			{
				temp += s[i];
			}
			i++;
		}

		string t;
		for (int j = 0; j < k; j++)
		{
			t.append(temp);
		}

		return make_pair(i, t);
	}

	string decodeString(string s)
	{
		return decodeString(s, 0, 1).second;
	}
};