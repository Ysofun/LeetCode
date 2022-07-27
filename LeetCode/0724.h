#pragma once





class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		
		int NumsSize = nums.size();
		
		vector<int> SumOfNums;
		SumOfNums.push_back(nums[0]);

		for (int i = 1; i < NumsSize; i++)
		{
			SumOfNums.push_back(SumOfNums[i - 1] + nums[i]);
		}

		for (int i = 0; i < NumsSize; i++)
		{
			if (i == 0)
			{
				if (SumOfNums[NumsSize - 1] - SumOfNums[i] == 0)
				{
					return i;
				}
			}
			else if (i == NumsSize - 1)
			{
				if (SumOfNums[NumsSize - 2] == 0)
				{
					return i;
				}
			}
			else 
			{
				if (SumOfNums[i - 1] == SumOfNums[NumsSize - 1] - SumOfNums[i])
				{
					return i;
				}
			}
		}

		return -1;
	}
};