#pragma once
#include <cstddef>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* rootMirror;
public:

	void BuildMirrorTree(TreeNode* root)
	{
		TreeNode* temp;
		if (root->right)
		{
			rootMirror->left = new TreeNode(root->right->val);
			temp = rootMirror;
			rootMirror = rootMirror->left;
			BuildMirrorTree(root->right);
			rootMirror = temp;
		}
		if (root->left)
		{
			rootMirror->right = new TreeNode(root->left->val);
			temp = rootMirror;
			rootMirror = rootMirror->right;
			BuildMirrorTree(root->left);
			rootMirror = temp;
		}
	}

	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
		{
			return {};
		}
		rootMirror = new TreeNode(root->val);
		TreeNode* currentRoot = rootMirror;
		BuildMirrorTree(root);
		return currentRoot;
	}
};