#pragma once



class Solution {
public:

	int ans = 0;

	int CalculateHeight(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int LHeight = CalculateHeight(root->left);
		int RHeight = CalculateHeight(root->right);

		ans = max(ans, LHeight + RHeight);
		return max(LHeight, RHeight) + 1;
	}

	int diameterOfBinaryTree(TreeNode* root) {
		CalculateHeight(root);
		return ans;
	}
};