#pragma once
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> numMap;
        for (int num : nums)
        {
            if (!numMap[num])
            {
                numMap[num] = true;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};