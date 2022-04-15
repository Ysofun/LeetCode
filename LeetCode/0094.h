#pragma once
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	void Inorder(TreeNode* root, vector<int>& ret)
	{
		if (root == nullptr)
		{
			return;
		}

		Inorder(root->left, ret);
		ret.push_back(root->val);
		Inorder(root->right, ret);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		Inorder(root, ret);
		return ret;
	}
};