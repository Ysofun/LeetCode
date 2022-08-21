#pragma once



class Solution {
public:

	int n;
	vector<int> BusSeat;
	vector<bool> bIsBusUsed;
	vector<vector<bool>> BusEdge;
	unordered_map<int, set<int>> StationToBus;

	int numBusesToDestination(int SourceBus)
	{
		if (BusSeat[SourceBus] == 1) { return BusSeat[SourceBus]; }

		bIsBusUsed[SourceBus] = true;
		int ans = 501;
		for (int i = 0; i < n; i++)
		{
			if (BusEdge[SourceBus][i] && !bIsBusUsed[i])
			{
				if (BusSeat[i] != -1) ans = min(ans, BusSeat[i]);
				else
				{
					int ret = numBusesToDestination(i);
					ans = ret == -1 ? ans : min(ans, ret);
				}
			}
		}

		bIsBusUsed[SourceBus] = false;
		BusSeat[SourceBus] = ans == 501 ? -1 : ans + 1;
		return BusSeat[SourceBus];
	}

	int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
		if (source == target) { return 0; }

		n = routes.size();
		BusSeat.resize(n, -1);
		bIsBusUsed.resize(n, false);
		BusEdge.resize(n, vector<bool>(n, false));

		for (int i = 0; i < n; i++)
		{
			for (int& Station : routes[i])
			{
				for (auto& j : StationToBus[Station])
				{
					BusEdge[i][j] = BusEdge[j][i] = true;
				}
				StationToBus[Station].insert(i);
				if (Station == target) { BusSeat[i] = 1; }
			}
		}

		int ans = 501;
		for (auto& Bus : StationToBus[source])
		{
			int ret = numBusesToDestination(Bus);
			BusSeat[Bus] = ret == -1 ? BusSeat[Bus] : min(BusSeat[Bus], ret);
			ans = BusSeat[Bus] == -1 ? ans : min(ans, BusSeat[Bus]);
		}

		return ans == 501 ? -1 : ans;
	}
};