#pragma once

class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		vector<int> TempVector;
		TempVector.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			TempVector.push_back(TempVector[i - 1] + nums[i]);
		}
		return TempVector;
	}
};