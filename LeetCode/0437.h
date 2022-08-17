#pragma once



class Solution {
public:

	unordered_map<long long, int> PreSum;

	int pathSum(TreeNode* root, long long Sum, int TargetSum)
	{
		if (root == nullptr) { return 0; }

		int ret = 0;
		Sum += root->val;
		if (PreSum.count(Sum - TargetSum)) { ret += PreSum[Sum - TargetSum]; }

		PreSum[Sum]++;
		ret += pathSum(root->left, Sum, TargetSum);
		ret += pathSum(root->right, Sum, TargetSum);
		PreSum[Sum]--;

		return ret;
	}

	int pathSum(TreeNode* root, int targetSum) {
		PreSum[0] = 1;
		return pathSum(root, 0, targetSum);
	}
};