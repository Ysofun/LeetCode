#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[i].size())
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            if (matrix[i][j] < target)
            {
                j++;
            }
            else 
            {
                i--;
            }
        }
        return false;
    }
};