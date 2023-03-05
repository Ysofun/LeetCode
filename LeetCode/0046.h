#pragma once
class Solution {
public:
	vector<vector<int>> ans;
	vector<int> temp;
	unordered_set<int> bNumUsed;
	void DFS(vector<int>& nums, int size)
	{
		if (size == nums.size())
		{
			ans.emplace_back(temp);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (!bNumUsed.count(nums[i]))
			{
				bNumUsed.insert(nums[i]);
				temp.emplace_back(nums[i]);
				DFS(nums, size + 1);
				temp.pop_back();
				bNumUsed.erase(nums[i]);
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		DFS(nums, 0);
		return ans;
	}
};