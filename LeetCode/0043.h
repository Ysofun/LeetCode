#pragma once
#include <string>
using namespace std;


class Solution {
public:

	/*string add(string num1, string num2)
	{
		string res;
		int i = num1.size() - 1, j = num2.size() - 1;
		int sum = 0;
		while (i >= 0 && j >= 0)
		{
			sum += num1[i] - '0' + num2[j] - '0';
			res += sum % 10 + '0';
			sum = sum / 10;

			i--;
			j--;
		}

		if (i < 0)
		{
			while (j >= 0)
			{
				sum += num2[j] - '0';
				res += sum % 10 + '0';
				sum = sum / 10;

				j--;
			}
		}
		else
		{
			while (i >= 0)
			{
				sum += num1[i] - '0';
				res += sum % 10 + '0';
				sum = sum / 10;

				i--;
			}
		}

		res = sum == 0 ? res : res + static_cast<char>(sum % 10 + '0');
		reverse(res.begin(), res.end());

		return res;
	}

	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
		{
			return "0";
		}

		string res;

		for (int i = num1.size() - 1; i >= 0; i--)
		{
			string temp;
			int tempNum = 0;
			for (int j = num2.size() - 1; j >= 0; j--)
			{
				int mul = (num1[i] - '0') * (num2[j] - '0');
				int one = mul % 10;
				int ten = mul / 10;

				temp += static_cast<char>((one + tempNum) % 10 + '0');
				tempNum = (one + tempNum) / 10 + ten;
			}

			temp = tempNum == 0 ? temp : temp + static_cast<char>(tempNum + '0');
			reverse(temp.begin(), temp.end());
			for (int k = i; k < num1.size() - 1; k++)
			{
				temp += '0';
			}

			res = add(res, temp);
		}

		return res;
	}*/


	string multiply(string num1, string num2)
	{
		int n = num1.size(), m = num2.size();
		string res(n + m, '0');

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				int mul = res[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0');
				res[i + j + 1] = mul % 10 + '0';
				res[i + j] += mul / 10;
			}
		}

		if (res[0] == '0')
		{
			if (res[1] == '0')
				return "0";
			else
				return res.substr(1, res.size());
		}
		else
		{
			return res;
		}
	}
};