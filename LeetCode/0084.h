#pragma once
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n, n - 1);
        vector<int> left(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                right[st.top()] = i - 1;
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
};