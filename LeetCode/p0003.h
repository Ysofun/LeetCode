#pragma once
#include <vector>
#include <map>
using namespace std;

//class Solution {
//public:
//    int findRepeatNumber(vector<int>& nums) {
//        int i = 0;
//        while (i < nums.size())
//        {
//            if (nums[i] != i)
//            {
//                if (nums[nums[i]] == nums[i]) { return nums[i]; }
//                swap(nums[i], nums[nums[i]]);
//            }
//            else { i++; }
//        }
//        return -1;
//    }
//};

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		while (l < r)
		{
			int mid = (l + r) / 2;
			int count = 0;
			for (int num : nums)
			{
				if (num <= mid) { count++; }
			}
			
			if (count > mid + 1) { r = mid; }
			else { l = mid + 1; }
		}

		return l;
	}
};