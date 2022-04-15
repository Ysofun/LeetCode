#pragma once
#include <vector>
using namespace std;

class QuickSort
{
public:
	void Sort(std::vector<int>& arr, int left, int right)
	{
		if (left < right)
		{
			int partitionIndex = Partition(arr, left, right);
			Sort(arr, left, partitionIndex - 1);
			Sort(arr, partitionIndex + 1, right);
		}
	}

	int Partition(std::vector<int>& arr, int left, int right)
	{
		int pivot = left;

		for (int i = pivot; i <= right; i++)
		{
			if (arr[i] < arr[pivot])
			{
				Swap(arr[i], arr[pivot]);
				pivot++;
			}
		}
		return pivot;
	}

	void Swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
};