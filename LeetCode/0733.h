#pragma once



class Solution {
public:

	void FillColor(vector<vector<int>>& image, int x, int y, int color, int NewColor)
	{
		image[x][y] = NewColor;

		if (x + 1 < image.size() && image[x + 1][y] == color)
		{
			FillColor(image, x + 1, y, color, NewColor);
		}

		if (x - 1 >= 0 && image[x - 1][y] == color)
		{
			FillColor(image, x - 1, y, color, NewColor);
		}

		if (y + 1 < image[0].size() && image[x][y + 1] == color)
		{
			FillColor(image, x, y + 1, color, NewColor);
		}

		if (y - 1 >= 0 && image[x][y - 1] == color)
		{
			FillColor(image, x, y - 1, color, NewColor);
		}
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		if (image[sr][sc] != color)
		{
			FillColor(image, sr, sc, image[sr][sc], color);
		}
		return image;
	}
};