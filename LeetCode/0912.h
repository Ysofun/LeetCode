#pragma once

class Solution {
public:

	void QuickSort(vector<int>& arr, int l, int r)
	{
		if (l >= r) { return; }

		int mid = rand() % (r - l + 1) + l;
		swap(arr[mid], arr[l]);
		int pivot = arr[l];

		int i = l + 1, j = r, k = l;
		while (i <= j)
		{
			if (arr[i] < pivot)
			{
				swap(arr[i], arr[k]);
				k++;
				i++;
			}
			else if (arr[i] > pivot)
			{
				swap(arr[i], arr[j]);
				j--;
			}
			else
			{
				i++;
			}
		}

		QuickSort(arr, l, k - 1);
		QuickSort(arr, i, r);
	}

	vector<int> sortArray(vector<int>& nums) {
		QuickSort(nums, 0, nums.size() - 1);
		return nums;
	}
};