#pragma once
#include <cstddef>
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool juageSymmetric(TreeNode* L, TreeNode* R)
	{
		if (!L && !R) return true;
		if (!L || !R || L->val != R->val) return false;
		return juageSymmetric(L->left, R->right) && juageSymmetric(L->right, R->left);
	}
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return juageSymmetric(root->left, root->right);
	}
};