#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        if (num == 0) return 1;
        vector<int> numbers;
        while (num != 0)
        {
            numbers.push_back(num % 10);
            num /= 10;
        }
        reverse(numbers.begin(), numbers.end());

        vector<int> dp(numbers.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < numbers.size(); i++)
        {
            dp[i] += dp[i - 1];
            if (numbers[i - 1] * 10 + numbers[i] < 26 && numbers[i - 1] != 0)
            {
                dp[i] += i - 2 > 0 ? dp[i - 2] : 1;
            }
        }
        return dp[numbers.size() - 1];
    }
};