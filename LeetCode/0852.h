#pragma once

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid]) { return mid; }
            if (arr[mid - 1] < arr[mid]) { l = mid + 1; }
            else { r = mid - 1; }
        }

        return -1;
    }
};