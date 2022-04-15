#pragma once
#include <vector>
using namespace std;

class Solution {
public:
/*
#pragma region Ä£Äâ
    int maxProduct(vector<int>& nums) {
        bool hasZero = false;
        int sum = 0;
        int firstNeg = -1, lastNeg = -1, negSum = 0, preFirstMul, preLastMul;
        int curMul = 1, maxMul = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                hasZero = true;
                if (sum == 1) maxMul = max(maxMul, curMul);
                else if (sum > 1)
                {
                    if (negSum % 2 == 0) maxMul = max(maxMul, curMul);
                    else maxMul = max(max(maxMul, curMul / preFirstMul), preLastMul / nums[lastNeg]);
                }
                sum = 0;
                firstNeg = -1;
                lastNeg = -1;
                negSum = 0;
                curMul = 1;
                continue;
            }
            sum++;
            curMul *= nums[i];
            if (nums[i] < 0)
            {
                negSum++;
                if (firstNeg == -1)
                {
                    preFirstMul = curMul;
                    firstNeg = i;
                }
                preLastMul = curMul;
                lastNeg = i;
            }
        }
        if (sum == 1) maxMul = max(maxMul, curMul);
        else if (sum > 1)
        {
            if (negSum % 2 == 0) maxMul = max(maxMul, curMul);
            else maxMul = max(max(maxMul, curMul / preFirstMul), preLastMul / nums[lastNeg]);
        }
        return hasZero ? max(maxMul, 0) : maxMul;
    }
#pragma endregion
*/
    int maxProduct(vector<int>& nums) {
        int curMin = nums[0], curMax = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int curmax = curMax, curmin = curMin;
            curMax = max(max(curmax * nums[i], curmin * nums[i]), nums[i]);
            curMin = min(min(curmin * nums[i], curmax * nums[i]), nums[i]);
            ans = max(ans, curMax);
        }
        return ans;
    }
};