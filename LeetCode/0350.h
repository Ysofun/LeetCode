#pragma once
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> numMap;
        vector<int> ans;
        for (int num : nums1)
        {
            if (numMap.find(num) == numMap.end()) numMap.insert(pair<int, int>(num, 1));
            else numMap[num]++;
        }
        for (int num : nums2)
        {
            if (numMap.find(num) != numMap.end() && numMap[num] != 0)
            {
                ans.push_back(num);
                numMap[num]--;
            }
        }
        return ans;
    }
};