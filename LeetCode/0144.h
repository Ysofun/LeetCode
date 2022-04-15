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
	void Preorder(vector<int>& ret, TreeNode* root)
	{
		if (!root)
		{
			return;
		}

		ret.push_back(root->val);
		Preorder(ret, root->left);
		Preorder(ret, root->right);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		Preorder(ret, root);
		return ret;
	}
};