#pragma once



class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int mid = l + ((r - l + 1) >> 1);

			if (nums[mid] == target) { return mid; }
			if (nums[mid] > nums[0])
			{
				if (nums[mid] > target)
				{
					if (target >= nums[0]) { r = mid - 1; }
					else { l = mid + 1; }
				}
				else { l = mid + 1; }
			}
			else
			{
				if (nums[mid] > target) { r = mid - 1; }
				else
				{
					if (target >= nums[0]) { r = mid - 1; }
					else { l = mid + 1; }
				}
			}
		}

		return -1;
	}
};