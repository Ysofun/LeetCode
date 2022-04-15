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
	bool flag = false;
public:
	bool juageSameTree(TreeNode* a, TreeNode* b)
	{
		if (!b) return true;
		if ((!a && b) || a->val != b->val) return false;
		return juageSameTree(a->left, b->left) && juageSameTree(a->right, b->right);

	}
	void PreOrder(TreeNode* a, TreeNode* b)
	{
		if (!a || flag) return;
		if (a->val == b->val)
		{
			flag = juageSameTree(a, b);
			if (flag) return;
		}
		PreOrder(a->left, b);
		PreOrder(a->right, b);
	}
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (!A || !B)
		{
			return false;
		}
		PreOrder(A, B);
		return flag;
	}
};