#pragma once



class Solution {
public:

	vector<int> Heap;

	void HeapInsert(int num)
	{
		Heap.emplace_back(num);
		int curr = Heap.size() - 1;
		int parent = curr == 0 ? 0 : (curr - 1) >> 1;

		while (parent >= 0 && curr != parent)
		{
			if (Heap[parent] > Heap[curr])
			{
				swap(Heap[parent], Heap[curr]);
			}

			curr = parent;
			parent = (parent - 1) >> 1;
		}
	}

	void HeapSort(vector<int>& res, int k)
	{
		while (res.size() != k)
		{
			res.emplace_back(Heap[0]);
			
			swap(Heap[0], Heap[Heap.size() - 1]);
			Heap.pop_back();

			int idx = 0;
			while (idx < Heap.size())
			{
				int lchild = idx * 2 + 1;
				int rchild = idx * 2 + 2;
				int child;
				if (rchild >= Heap.size())
				{
					if (lchild >= Heap.size())
					{
						break;
					}
					child = lchild;
				}
				else 
				{
					child = Heap[lchild] <= Heap[rchild] ? lchild : rchild;
				}

				if (Heap[idx] > Heap[child])
				{
					swap(Heap[idx], Heap[child]);
				}
				else
				{
					break;
				}

				idx = child;
			}
		}
	}

	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		for (int i = 0; i < arr.size(); i++)
		{
			HeapInsert(arr[i]);
		}

		vector<int> ans;
		HeapSort(ans, k);
		return ans;
	}
};
