#pragma once



class Solution {
public:
	/*vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> numsMap;
		for (int i = 0; i < nums.size(); i++)
		{
			auto it = numsMap.find(target - nums[i]);
			if (it != numsMap.end())
			{
				return { it->second, i };
			}
			numsMap[nums[i]] = i;
		}
		return {};
	}*/

	vector<int> twoSum(vector<int>& nums, int target)
	{
		map<int, int> FindNum;
		for (int i = 0; i < nums.size(); i++)
		{
			map<int, int>::iterator it = FindNum.find(target - nums[i]);
			if (it != FindNum.end())
			{
				return { it->second, i };
			}
			FindNum.insert(make_pair(nums[i], i));
		}

		return {};
	}
};