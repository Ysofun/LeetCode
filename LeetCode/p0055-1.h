#pragma once
#include <cstddef>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int ans = 0;
public:
	int GetHeight(TreeNode* root)
	{
		if (!root) return 0;
		int height = std::max(GetHeight(root->left), GetHeight(root->right)) + 1;
		ans = std::max(ans, height);
		return height;
	}
    int maxDepth(TreeNode* root) {
		GetHeight(root);
		return ans;
    }
};