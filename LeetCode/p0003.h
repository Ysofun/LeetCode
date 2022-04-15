#pragma once
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, bool> numExist;
        for (auto& num : nums)
        {
            if (numExist.find(num) != numExist.end())
            {
                return num;
            }
            else
            {
                numExist.insert(pair<int, bool>(num, true));
            }
        }
        return -1;
    }
};