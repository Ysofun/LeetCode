#pragma once
#include <vector>
using namespace std;

class Solution {
    vector<vector<bool>> isRobortWalked;
public:
    bool CanRobortWalk(int x, int y, int k)
    {
        while (x)
        {
            k -= x % 10;
            if (k < 0) return false;
            x /= 10;
        }
        while (y)
        {
            k -= y % 10;
            if (k < 0) return false;
            y /= 10;
        }
        return true;
    }

    int FindRobortWay(int& m, int& n, int x, int y, int k)
    {
        if (x >= m || y >= n || !CanRobortWalk(x, y, k) || isRobortWalked[x][y]) return 0;
        isRobortWalked[x][y] = true;
        return FindRobortWay(m, n, x + 1, y, k) + FindRobortWay(m, n, x, y + 1, k) + 1;
    }

    int movingCount(int m, int n, int k) {
        isRobortWalked.resize(m, vector<bool>(n, false));
        return FindRobortWay(m, n, 0, 0, k);
    }
};