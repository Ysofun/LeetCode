#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i = 0;
        while (i != n / 2)
        {
            int m = n - i - 1;
            for (int j = i; j < m; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[m - j + i][i];
                matrix[m - j + i][i] = matrix[m][m - j + i];
                matrix[m][m - j + i] = matrix[j][m];
                matrix[j][m] = temp;
                
            }
            i++;
        }
    }
};