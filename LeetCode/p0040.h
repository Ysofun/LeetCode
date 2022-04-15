#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> arr2 = arr;
        sort(arr2.begin(), arr2.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(arr2[i]);
        }
        return ans;
    }
};