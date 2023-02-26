#pragma once
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int preND = arr[0], preD = arr[0], ans = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            preD = max(preND, preD + arr[i]);
            preND = max(preND + arr[i], arr[i]);

            ans = max(ans, preD);
            ans = max(ans, preND);
        }

        return ans;
    }
};