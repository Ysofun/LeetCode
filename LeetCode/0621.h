#pragma once



class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> a(26);
		for (char& ch : tasks)
		{
			a[ch - 'A']++;
		}

		int maxExec = 0;
		int maxCount = 0;
		for (int& _a : a)
		{
			if (_a > maxExec)
			{
				maxExec = _a;
				maxCount = 0;
			}
			if (_a == maxExec)
			{
				maxCount++;
			}
		}

		int res = (maxExec - 1) * (n + 1) + maxCount;
		return tasks.size() > res ? tasks.size() : res;
	}
};