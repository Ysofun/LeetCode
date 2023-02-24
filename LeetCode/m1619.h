#pragma once
class Solution {
public:

    int n, m;
    int xGo[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int yGo[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    int dfs(vector<vector<int>>& land, int x, int y)
    {   
        int sum = 0;
        for (int i = 0; i < 8; i++)
        {
            int nextX = x + xGo[i], nextY = y + yGo[i];
            if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < m && land[nextX][nextY] == 0)
            {
                land[nextX][nextY] = 1;
                sum++;
                sum += dfs(land, nextX, nextY);
            }
        }

        return sum;
    }

    vector<int> pondSizes(vector<vector<int>>& land) {
        n = land.size(), m = land[0].size();
        vector<vector<bool>> bCal(n, vector<bool>(m, false));

        vector<int> pSize;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (land[i][j] == 0)
                {
                    land[i][j] = 1;
                    pSize.push_back(dfs(land, i, j) + 1);
                }
            }
        }

        sort(pSize.begin(), pSize.end());
        return pSize;
    }
};