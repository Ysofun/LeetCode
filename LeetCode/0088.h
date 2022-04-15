#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m; i < n + m; i++)
		{
			nums1[i] = nums2[i - m];
		}
		sort(nums1.begin(), nums1.end());
	}
	*/
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int p1 = m - 1, p2 = n - 1, p3 = m + n - 1;
		while (p1 >= 0 || p2 >= 0)
		{
			if (p1 < 0)
			{
				nums1[p3] = nums2[p2];
				p3--;
				p2--;
			}
			else if (p2 < 0)
			{
				nums1[p3] = nums1[p1];
				p3--;
				p1--;
			}
			else
			{
				if (nums1[p1] > nums2[p2])
				{
					nums1[p3] = nums1[p1];
					p3--;
					p1--;
				}
				else
				{
					nums1[p3] = nums2[p2];
					p3--;
					p2--;
				}
			}
		}
	}
};