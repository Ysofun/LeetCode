class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size() + 1);
		int idx = 1;
		dp[idx] = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > dp[idx])
			{
				dp[++idx] = nums[i];
				continue;
			}
			int l = 1, r = idx, pos = 0;;
			while (l <= r)
			{
				int mid = l + ((r - l + 1) >> 1);
				if (dp[mid] < nums[i]) 
				{ 
					pos = mid;
					l = mid + 1; 
				}
				else { r = mid - 1; }
			}
			dp[pos + 1] = nums[i];
		}
		return idx;
	}
};