#pragma once
class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> stk;
		int ans = 0;
		for (int i = 0; i < height.size(); i++)
		{
			while (!stk.empty() && height[stk.top()] < height[i])
			{
				int top = stk.top();
				stk.pop();
				if (stk.empty()) { break; }

				int left = stk.top();
				int width = i - left - 1;
				int h = min(height[left], height[i]) - height[top];
				ans += width * h;
			}
			stk.push(i);
		}

		return ans;
	}
};