#pragma once
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums[i] > 0) { break; }
			if (i > 0 && nums[i] == nums[i - 1]) { continue; }

			int k = n - 1;
			int target = -nums[i];
			for (int j = i + 1; j < n; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1]) { continue; }

				while (j < k && nums[j] + nums[k] > target) { k--; }
				if (j == k) { break; }
				if (nums[j] + nums[k] == target) { ans.push_back({ nums[i], nums[j], nums[k] }); }
			}
		}

		return ans;
	}
};