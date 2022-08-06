#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	/*int QuickSort(vector<int>& nums, int l, int r, int k)
	{
		cout << l << ' ' << k << endl;
		if (l == r) return nums[l];
		int i = l, j = r, tmp = nums[l];
		while (i != j)
		{
			while (i < j && nums[j] >= tmp)
			{
				j--;
			}
			if (i < j)
			{
				nums[i] = nums[j];
				i++;
			}
			while (i < j && nums[i] < tmp)
			{
				i++;
			}
			if (i < j)
			{
				nums[j] = nums[i];
				j--;
			}
		}
		nums[i] = tmp;
		if (i == k)
		{
			return nums[i];
		}
		else if (i < k)
		{
			return QuickSort(nums, i + 1, r, k);
		}
		else
		{
			return QuickSort(nums, l, i - 1, k);
		}
	}*/

	template<typename T>
	int QuickSort(vector<T>& nums, int k, int l, int r)
	{
		if (l >= r)
		{
			return nums[l];
		}

		int i = l, j = r;
		T pivot = nums[l];

		while (i < j)
		{
			while (i < j && nums[j] >= pivot)
			{
				j--;
			}
			if (i < j)
			{
				nums[i++] = nums[j];
			}

			while (i < j && nums[i] <= pivot)
			{
				i++;
			}
			if (i < j)
			{
				nums[j--] = nums[i];
			}
		}

		nums[i] = pivot;
		if (i == k)
		{
			return nums[i];
		}

		return i < k ? QuickSort(nums, k, i + 1, r) : QuickSort(nums, k, l, i - 1);
	}

    int findKthLargest(vector<int>& nums, int k) {
        return QuickSort<int>(nums, nums.size() - k, 0, nums.size() - 1);
    }
};