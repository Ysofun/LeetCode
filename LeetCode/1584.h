#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int pointNum = points.size();
        vector<vector<int>> connectGraph(pointNum, vector<int>(pointNum));

        for (int i = 0; i < pointNum; i++)
        {
            for (int j = i + 1; j < pointNum; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                connectGraph[i][j] = dist;
                connectGraph[j][i] = dist;
            }
        }
       
        vector<int> lowcost(pointNum, 0x7fffffff);
        vector<int> v(pointNum, -1);
        int minCostCount = 0;

        v[0] = 0;
        for (int i = 0; i < pointNum; i++)
        {
            if (i != 0)
            {
                lowcost[i] = connectGraph[0][i];
            }
        }

        for (int i = 1; i < pointNum; i++)
        {
            int minCurrent = 0x7fffffff;
            int minPoint = -1;
            for (int j = 1; j < pointNum; j++)
            {
                if (v[j] != 0)
                {
                    if (lowcost[j] < minCurrent)
                    {
                        minCurrent = lowcost[j];
                        minPoint = j;
                    }
                }
            }

            minCostCount += minCurrent;
            v[minPoint] = 0;
            lowcost[minPoint] = -1;

            for (int j = 0; j < pointNum; j++)
            {
                if (v[j] == -1 && connectGraph[j][minPoint] < lowcost[j])
                {
                    lowcost[j] = connectGraph[j][minPoint];
                }
            }
        }

        return minCostCount;
    }
};