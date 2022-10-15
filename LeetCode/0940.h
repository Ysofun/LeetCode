#pragma once


#define MOD_VAL 1000000007
class Solution {
public:
	int distinctSubseqII(string s) {
		int n = s.size();
		vector<int> sum(n);
		vector<int> last(26, -1);
		sum[0] = 1;
		last[s[0] - 'a'] = 0;
		for (int i = 1; i < n; i++)
		{
			if (last[s[i] - 'a'] == -1) { sum[i] = (2 * sum[i - 1] + 1) % MOD_VAL; }
			else if (last[s[i] - 'a'] == 0) { sum[i] = 2 * sum[i - 1] % MOD_VAL; }
			else { sum[i] = (2 * sum[i - 1] % MOD_VAL - sum[last[s[i] - 'a'] - 1]) % MOD_VAL; }
			last[s[i] - 'a'] = i;
		}
		return sum[n - 1] < 0 ? sum[n - 1] + MOD_VAL : sum[n - 1];
	}
};