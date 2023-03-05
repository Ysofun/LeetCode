#pragma once
class Solution {
public:
	TreeNode* ans = nullptr;
	bool DFS(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == nullptr) { return false; }
		bool lson = DFS(root->left, p, q);
		bool rson = DFS(root->right, p, q);
		if ((lson && rson) || ((lson || rson) && (root == p || root == q))) { ans = root; }
		return lson || rson || root == p || root == q;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		DFS(root, p, q);
		return ans;
	}
};