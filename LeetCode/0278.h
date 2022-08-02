#pragma once



class Solution {
public:
	int firstBadVersion(int n) {
		int l = 1, r = n;
		int ans;

		while (l <= r)
		{
			int mid = l + (r - l) >> 1;
			if (isBadVersion(mid))
			{
				r = mid - 1;
				ans = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		return l;
	}
};