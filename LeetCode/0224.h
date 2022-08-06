#pragma once



class Solution {
public:

	int calculate(const string& s, int l, int r)
	{
		int res = 0;
		int sign = 1;

		for (int i = l; i < r; i++)
		{
			if (s[i] == ' ')
			{
				continue;
			}

			if (s[i] == '+')
			{
				sign = 1;
			}

			else if (s[i] == '-')
			{
				sign = -1;
			}

			else
			{
				if (s[i] == '(')
				{
					int l = 1, r = 0;
					int j = i + 1;
					while (l != r)
					{
						l = s[j] == '(' ? l + 1 : l;
						r = s[j] == ')' ? r + 1 : 1;
						j++;
					}
					res += sign * calculate(s, i + 1, j);
					i = j;
				}
				else
				{
					int num = 0;
					while (s[i] >= '0' && s[i] <= '9')
					{
						num = num * 10 + (s[i] - '0');
						i++;
					}
					i--;
					res += sign * num;
				}
			}
		}

		return res;
	}


	int calculate(string s) {
		return calculate(s, 0, s.size());
	}
};