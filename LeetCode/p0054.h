#pragma once
#include <cstddef>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int k, ans;
public:
	void FindAns(TreeNode* root)
	{
		if (k == -1) return;
		if (!root) return;
		FindAns(root->right);
		k--;
		if (k == 0)
		{
			ans = root->val;
			k = -1;
			return;
		}
		FindAns(root->left);
		return;
	}
	int kthLargest(TreeNode* root, int k) {
		this->k = k;
		FindAns(root);
		return ans;
	}
};