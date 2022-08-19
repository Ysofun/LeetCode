#pragma once



class Solution {
public:
	
	void MidSearch(TreeNode* root, vector<int>& nums)
	{
		if (root == nullptr) { return; }

		MidSearch(root->left, nums);
		nums.emplace_back(root->val);
		MidSearch(root->right, nums);
	}

	int kthSmallest(TreeNode* root, int k) {
		vector<int> nums;
		MidSearch(root, nums);
		return nums[k - 1];
	}
};