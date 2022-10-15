#pragma once


//class Solution {
//public:
//	int hIndex(vector<int>& citations) {
//		int ans, n = citations.size();
//		int l = 0, r = n;
//		while (l <= r)
//		{
//			int mid = (l + r) >> 1;
//			int sum = 0;
//			for (int i = 0; i < n; i++)
//			{
//				if (citations[i] >= mid) { sum++; }
//			}
//			if (sum >= mid) 
//			{
//				ans = mid;
//				l = mid + 1; 
//			}
//			else { r = mid - 1; }
//		}
//
//		return ans;
//	}
//};


class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		vector<int> counter(n + 1);
		for (int i = 0; i < n; i++)
		{
			if (citations[i] >= n) { counter[n]++; }
			else { counter[citations[i]]++; }
		}

		int sum = 0;
		for (int i = n; i >= 0; i--)
		{
			sum += counter[i];
			if (sum >= i) { return i; }
		}

		return 0;
	}
};