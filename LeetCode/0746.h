#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        if (n == 0) return cost[0];
        if (n == 1) return min(cost[0], cost[1]);
        for (int i = 2; i < cost.size(); i++)
        {
            cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
        }
        return min(cost[n - 1], cost[n - 2]);
    }
};