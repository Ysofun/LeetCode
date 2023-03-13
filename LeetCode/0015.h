#pragma once
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> ans;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0) { break; }
			if (i != 0 && nums[i - 1] == nums[i]) { continue; }

			int target = -nums[i];
			int k = nums.size() - 1;
			for (int j = i + 1; j < k; j++)
			{
				if (j > i + 1 && nums[j - 1] == nums[j]) { continue; }
				while (j < k && nums[j] + nums[k] > target) { k--; }
				if (j >= k) { break; }
				if (nums[j] + nums[k] == target) { ans.push_back({ nums[i], nums[j], nums[k] }); }
			}
		}
		return ans;
	}
};