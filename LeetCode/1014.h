#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, maxVal = values[0];
        for (int i = 1; i < values.size(); i++)
        {
            ans = max(ans, maxVal - 1 + values[i]);
            maxVal = max(maxVal - 1, values[i]);
        }
        return ans;
    }
};