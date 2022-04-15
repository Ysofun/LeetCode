#pragma once
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}

		int lDepth = minDepth(root->left);
		int rDepth = minDepth(root->right);

		if (lDepth == 0 && rDepth == 0)
		{
			return 1;
		}
		else if (lDepth == 0 && rDepth != 0)
		{
			return rDepth + 1;
		}
		else if (lDepth != 0 && rDepth == 0)
		{
			return lDepth + 1;
		}
		else
		{
			return min(lDepth, rDepth) + 1;
		}
	}
};