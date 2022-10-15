#pragma once


class Solution {
public:
	bool reachingPoints(int sx, int sy, int tx, int ty) {
		while (tx > sx && ty > sy && tx != ty)
		{
			if (tx > ty) { tx %= ty; }
			else { ty %= tx; }
		}

		if (sx == tx && sy == ty) { return true; }
		else if (sx == tx) { return ty > sy && (ty - sy) % sx == 0; }
		else if (sy == ty) { return tx > sx && (tx - sx) % sy == 0; }
		else { return false; }
	}
};