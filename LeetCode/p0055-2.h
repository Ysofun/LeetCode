#pragma once
#include <cstddef>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool flag = true;
public:
	int GetHeight(TreeNode* root)
	{
		if (!flag) return 0;
		if (!root) return 0;
		int leftHeight = GetHeight(root->left);
		int rightHeight = GetHeight(root->right);
		if (abs(leftHeight - rightHeight) > 1) flag = false;
		return max(leftHeight, rightHeight) + 1;
	}
	bool isBalanced(TreeNode* root) {
		GetHeight(root);
		return flag;
	}
};