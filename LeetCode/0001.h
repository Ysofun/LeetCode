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
		sort(nums.begin(), nums.end());
		int j = nums.size() - 1;
		for (int i = 0; i < nums.size(); i++)
		{
			while (i < j && nums[i] + nums[j] > target) { j--; }
			if (i == j) { break; }
			if (nums[i] + nums[j] == target) { return { i, j }; }
		}
		return {};
	}
};