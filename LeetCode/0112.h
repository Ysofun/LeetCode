#pragma once
#include <vector>
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
	int sum = 0;
	int targetSum;
	bool flag = false;
	void GetSum(TreeNode* root)
	{
		if (flag)
		{
			return;
		}
		if (!root->left && !root->right)
		{
			sum += root->val;
			if (sum == targetSum)
			{
				flag = true;
			}
			sum -= root->val;
			return;
		}
		sum += root->val;
		if (root->left) GetSum(root->left);
		if (root->right) GetSum(root->right);
		sum -= root->val;
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root)
		{
			return false;
		}
		this->targetSum = targetSum;
		GetSum(root);
		return flag;
	}
};