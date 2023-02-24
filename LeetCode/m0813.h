#pragma once
class Solution {
public:


    int pileBox(vector<vector<int>>& box) {
        auto cmp = [](const vector<int>& x, const vector<int>& y)
        {
            return x[2] < y[2];
        };

        sort(box.begin(), box.end(), cmp);


    }
};