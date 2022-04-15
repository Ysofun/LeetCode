#pragma once
#include "Sort.h"

class BubbleSort
{
public:
	void Sort(std::vector<int>& arr)
	{
		for (int i = 0; i < arr.size() - 1; i++)
		{
			for (int j = 0; j < arr.size() - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					Swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	void Swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
};