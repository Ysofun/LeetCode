#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int posLen = 0, negLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cout << "posLen: " << posLen << " negLen: " << negLen << endl;
            if (nums[i] > 0)
            {
                posLen++;
                negLen = negLen > 0 ? negLen + 1 : 0;
            }
            else if (nums[i] < 0)
            {
                int newPosLen = negLen > 0 ? negLen + 1 : 0;
                int newNegLen = posLen + 1;
                posLen = newPosLen;
                negLen = newNegLen;
            }
            else posLen = negLen = 0;
            ans = max(ans, posLen);
        }
        return ans;
    }
};