#pragma once
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		if (root == nullptr) { return {}; }
		queue<TreeNode*> bfsCache;
		vector<int> ans;
		bfsCache.push(root);
		while (!bfsCache.empty())
		{
			for (int i = bfsCache.size() - 1; i >= 0; i--)
			{
				TreeNode* node = bfsCache.front();
				bfsCache.pop();
				if (i == 0) { ans.emplace_back(node->val); }

				if (node->left != nullptr) { bfsCache.emplace(node->left); }
				if (node->right != nullptr) { bfsCache.emplace(node->right); }
			}
		}

		return ans;
	}
};