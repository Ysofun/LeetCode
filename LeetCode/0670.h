#pragma once


class Solution {
public:
	int maximumSwap(int num) {
		string numArray = to_string(num);
		int len = numArray.size();
		int maxIdx = len - 1;
		int idx1 = -1, idx2 = -1;
		for (int i = len - 1; i >= 0; i--)
		{
			if (numArray[i] > numArray[maxIdx]) { maxIdx = i; }
			else if (numArray[i] < numArray[maxIdx])
			{
				idx1 = i;
				idx2 = maxIdx;
			}
		}

		if (idx1 >= 0)
		{
			swap(numArray[idx1], numArray[idx2]);
			return stoi(numArray);
		}
		else { return num; }
	}
};