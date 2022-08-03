#pragma once



class Solution {
public:

	vector<int> Sequence;

	void MidFind(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}

		MidFind(root->left);
		Sequence.emplace_back(root->val);
		MidFind(root->right);
	}

	bool isValidBST(TreeNode* root) {
		MidFind(root);

		for (int i = 1; i < Sequence.size(); i++)
		{
			if (Sequence[i - 1] >= Sequence[i])
			{
				return false;
			}
		}

		return true;
	}
};