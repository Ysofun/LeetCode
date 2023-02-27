#pragma once
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numberOfArrays(string s, int k) {
        int len = s.length();
        vector<int> dp(len + 1);
        dp[len] = 1;

        vector<int> kVec;
        int temp = k;
        while (temp > 0)
        {
            kVec.emplace_back(temp % 10);
            temp /= 10;
        }
        int kSize = kVec.size();
        reverse(kVec.begin(), kVec.end());

        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] - '0' > k) { return 0; }
            if (s[i] == '0') { continue; }

            for (int j = i + 1; j <= len && j < i + kSize; j++)
            {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }

            if (i + kSize <= len)
            {
                bool bBigger = false;
                for (int j = 0; j < kSize; j++)
                {
                    if (s[i + j] - '0' > kVec[j])
                    {
                        bBigger = true;
                        break;
                    }
                    if (s[i + j] - '0' < kVec[j]) { break; }
                }

                if (!bBigger) { dp[i] = (dp[i] + dp[i + kSize]) % MOD; }
            }
        }

        return dp[0];
    }
};