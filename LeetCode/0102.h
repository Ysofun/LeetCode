#pragma once
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr) { return {}; }
		vector<vector<int>> ans;
		queue<TreeNode*> BFSCache;
		BFSCache.push(root);
		while (!BFSCache.empty())
		{
			vector<int> level;
			int n = BFSCache.size();
			for (int i = 0; i < n; i++)
			{
				TreeNode* node = BFSCache.front();
				BFSCache.pop();
				level.emplace_back(node->val);
				if (node->left != nullptr) { BFSCache.emplace(node->left); }
				if (node->right != nullptr) { BFSCache.emplace(node->right); }
			}
			ans.emplace_back(level);
		}
		return ans;
	}
};