#pragma once


class Solution {
public:

	int ans;
	int Query(TreeNode* root)
	{
		if (root == nullptr) { return 0; }

		int lsum = Query(root->left);
		int rsum = Query(root->right);

		int ret = max(max(lsum, rsum) + root->val, root->val);
		ans = max(max(ans, ret), lsum + rsum + root->val);
		return ret;
	}

	int maxPathSum(TreeNode* root) {
		ans = root->val;
		Query(root);
		return ans;
	}
};