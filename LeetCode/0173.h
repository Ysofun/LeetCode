#pragma once



class BSTIterator {
private:
	int idx = 0;
	TreeNode* root;
	vector<int> nums;

	void InOrder(TreeNode* root)
	{
		if (root == nullptr) { return; }

		InOrder(root->left);
		nums.emplace_back(root->val);
		InOrder(root->right);
	}

public:
	BSTIterator(TreeNode* root) {
		this->root = root;
		InOrder(root);
	}

	int next() {
		return nums[idx++];
	}

	bool hasNext() {
		return idx < nums.size();
	}
};
