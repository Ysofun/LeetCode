#pragma once

class Solution {
public:

	template<typename T>
	void RandomizedQuicksort(vector<T>& nums, int l, int r)
	{
		if (l >= r) { return; }
		
		int pos = rand() % (r - l + 1) + l;
		swap(nums[l], nums[pos]);

		T pivot = nums[l];
		int i = l, j = r;
		while (i < j)
		{
			while (i < j && nums[j] >= pivot) { j--; }
			if (i < j) { nums[i] = nums[j]; }

			while (i < j && nums[i] <= pivot) { i++; }
			if (i < j) { nums[j] = nums[i]; }
		}

		nums[i] = pivot;

		RandomizedQuicksort(nums, l, i - 1);
		RandomizedQuicksort(nums, i + 1, r);
	}

	vector<int> sortArray(vector<int>& nums) {
		RandomizedQuicksort<int>(nums, 0, nums.size() - 1);
		return nums;
	}
};