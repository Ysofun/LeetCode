#pragma once



class Solution {
public:

	TreeNode* ans = nullptr;

	void FindAns(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == nullptr)
		{
			return;
		}

		if (root->val > p->val && root->val < q->val || root->val < p->val && root->val > q->val)
		{
			ans = root;
			return;
		}

		if (root->val == p->val)
		{
			ans = p;
			return;
		}

		if (root->val == q->val)
		{
			ans = q;
			return;
		}

		if (root->val < min(p->val, q->val))
		{
			FindAns(root->right, p, q);
		}

		if (root->val > max(p->val, q->val))
		{
			FindAns(root->left, p, q);
		}
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		FindAns(root, p, q);
		return ans;
	}
};