#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	static void printMatrix(vector<vector<int>>& nums)
	{
		int n = nums.size() - 1;
		int m = nums[0].size() - 1;
		int x = 0, y = 0;

		while (x <= n && y <= m)
		{
			if (x == n)
			{
				for (int j = y; j <= m; j++)
				{
					cout << nums[x][j] << ' ';
				}
				break;
			}
			if (y == m)
			{
				for (int j = y; j <= m; j++)
				{
					cout << nums[x][j] << ' ';
				}
				for (int i = x + 1; i <= n; i++)
				{
					cout << nums[i][m] << ' ';
				}
				break;
			}
			for (int j = y; j <= m; j++)
			{
				cout << nums[x][j] << ' ';
			}
			for (int i = x + 1; i <= n; i++)
			{
				cout << nums[i][m] << ' ';
			}
			for (int j = m - 1; j >= y; j--)
			{
				cout << nums[n][j] << ' ';
			}
			for (int i = n - 1; i > x; i--)
			{
				cout << nums[i][y] << ' ';
			}
			cout << endl;
			n--;
			m--;
			x++;
			y++;
		}
	}
};