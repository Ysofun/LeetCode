class Solution {
public:
    int BFPRT(vector<int>& arr, int l, int r, int k)
    {
        if (l == r) { return arr[l]; }

        int pivot = MedianOfMedians(arr, l, r);
        vector<int> equalPivotRange = Partition(arr, l, r, pivot);
        if (l + k >= equalPivotRange[0] && l + k <= equalPivotRange[1]) { return arr[equalPivotRange[0]]; }
        else if (l + k < equalPivotRange[0]) { return BFPRT(arr, l, equalPivotRange[0] - 1, k); }
        else { return BFPRT(arr, equalPivotRange[1] + 1, r, l + k - equalPivotRange[1] - 1); }
    }

    int MedianOfMedians(vector<int>& arr, int l, int r)
    {
        int n = r - l + 1;
        int extra = n % 5 == 0 ? 0 : 1;
        vector<int> medians(n / 5 + extra);
        for (int i = 0; i < medians.size(); i++)
        {
            medians[i] = ComputeMedian(arr, l + i * 5, min(l + i * 5 + 4, r));
        }
        return BFPRT(medians, 0, medians.size() - 1, medians.size() / 2);
    }

    vector<int> Partition(vector<int>& arr, int l, int r, int pivot)
    {
        int small = l - 1;
        int equal = 0;
        for (int i = l; i <= r; i++)
        {
            if (arr[i] < pivot)
            {
                small++;
                swap(arr[small], arr[i]);
                if (equal > 0) { swap(arr[i], arr[small + equal]); }
            }
            else if (arr[i] == pivot)
            {
                equal++;
                swap(arr[i], arr[small + equal]);
            }
        }
        return { small + 1, small + equal };
    }

    int ComputeMedian(vector<int>& arr, int l, int r)
    {
        sort(arr.begin() + l, arr.begin() + r + 1);
        return arr[l + ((r - l) >> 1)];
    }

    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.size() == 0) { return {}; }
        BFPRT(arr, 0, arr.size() - 1, k - 1);
        vector<int> ans;
        ans.assign(arr.begin(), arr.begin() + k);
        return ans;
    }
};