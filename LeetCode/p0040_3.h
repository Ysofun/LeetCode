#pragma once



class Solution 
{

public:

	void QuickSort(vector<int>& arr, int k, int l , int r)
	{
		if (l >= r)
		{
			return;
		}

		int i = l, j = r;
		int pivot = arr[l];

		while (i < j)
		{
			while (i < j && arr[j] > pivot)
			{
				j--;
			}
			if (i < j)
			{
				arr[i++] = arr[j];
			}

			while (i < j && arr[i] <= pivot)
			{
				i++;
			}
			if (i < j)
			{
				arr[j--] = arr[i];
			}
		}

		arr[i] = pivot;
		if (i >= k)
		{
			QuickSort(arr, k, l, i - 1);
		}
		else 
		{
			QuickSort(arr, k, l, i - 1);
			QuickSort(arr, k, i + 1, r);
		}
	}

	vector<int> getLeastNumbers(vector<int>& arr, int k) 
	{
		vector<int> ans;
		QuickSort(arr, k - 1, 0, arr.size() - 1);

		for (int i = 0; i < k; i++)
		{
			ans.emplace_back(arr[i]);
		}

		return ans;
	}

};