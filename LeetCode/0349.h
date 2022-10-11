#pragma once


class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;
		map<int, bool> numsMap;
		for (int i = 0; i < nums1.size(); i++)
		{
			if (numsMap.find(nums1[i]) == numsMap.end())
			{
				numsMap.insert(pair<int, bool>(nums1[i], true));
			}
		}

		for (int i = 0; i < nums2.size(); i++)
		{
			if (numsMap.find(nums2[i]) != numsMap.end() && numsMap[nums2[i]] == true)
			{
				ans.emplace_back(nums2[i]);
				numsMap[nums2[i]] = false;
			}
		}

		return ans;
	}
};