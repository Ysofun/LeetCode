#pragma once



class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> heap;

        for (int i = 0; i < stones.size(); i++)
        {
            heap.push(stones[i]);
        }

        while (!heap.empty() && heap.size() != 1)
        {
            int stone1 = heap.top();
            heap.pop();
            int stone2 = heap.top();
            heap.pop();

            cout << stone1 << ' ' << stone2 << endl;
            if (stone1 != stone2)
            {
                heap.push(abs(stone1 - stone2));
            }
        }

        return heap.empty() ? 0 : heap.top();
    }
};