#pragma once
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct NumData 
    {
        int idx;
        int val;
        NumData(int _idx, int _val) : idx(_idx), val(_val) {}
    };

    void JumpNext(vector<int>& next, vector<NumData>& arr)
    {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            while (!st.empty() && st.top() < arr[i].idx)
            {
                next[st.top()] = arr[i].idx;
                st.pop();
            }
            st.push(arr[i].idx);
        }
    }

    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<NumData> arrSorted1;
        vector<NumData> arrSorted2;
        for (int i = 0; i < n; i++)
        {
            arrSorted1.emplace_back(NumData(i, arr[i]));
            arrSorted2.emplace_back(NumData(i, arr[i]));
        }
        sort(arrSorted1.begin(), arrSorted1.end(), [](NumData a, NumData b)
            { 
                return a.val == b.val ? a.idx < b.idx : a.val < b.val;
            });

        sort(arrSorted2.begin(), arrSorted2.end(), [](NumData a, NumData b)
            {
                return a.val == b.val ? a.idx < b.idx : a.val > b.val;
            });

        vector<int> oddNext(n, -1);
        JumpNext(oddNext, arrSorted1);
        vector<int> evenNext(n, -1);
        JumpNext(evenNext, arrSorted2);

        vector<int> bOddCan(n);
        vector<int> bEvenCan(n);
        bOddCan[n - 1] = bEvenCan[n - 1] = 1;
        int ans = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (oddNext[i] == -1) { bOddCan[i] = -1; }
            else { bOddCan[i] = bEvenCan[oddNext[i]]; }
            if (evenNext[i] == -1) { bEvenCan[i] = -1; }
            else { bEvenCan[i] = bOddCan[evenNext[i]]; }

            if (bOddCan[i] == 1) { ans++; }
        }

        return ans;
    }
};