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
	bool flag = true;
	int CalHeight(TreeNode* root)
	{
		if (!flag)
		{
			return 0;
		}
		if (!root)
		{
			return 0;
		}
		int lHeight = CalHeight(root->left);
		int rHeight = CalHeight(root->right);
		if (abs(lHeight - rHeight) > 1)
		{
			flag = false;
			return 0;
		}
		return max(lHeight, rHeight) + 1;
	}

    bool isBalanced(TreeNode* root) {
		CalHeight(root);
		return flag;
    }
};