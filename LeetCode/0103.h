#pragma once
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == nullptr) { return {}; }
		queue<TreeNode*> BFSCache;
		BFSCache.push(root);
		vector<vector<int>> ans;
		bool bReverse = false;
		while (!BFSCache.empty())
		{
			vector<int> temp;
			for (int i = BFSCache.size() - 1; i >= 0; i--)
			{
				TreeNode* node = BFSCache.front();
				BFSCache.pop();
				temp.emplace_back(node->val);
				if (node->left) { BFSCache.push(node->left); }
				if (node->right) { BFSCache.push(node->right); }
			}
			if (bReverse) { reverse(temp.begin(), temp.end()); }
			bReverse = !bReverse;
			ans.emplace_back(temp);
		}
		return ans;
	}
};