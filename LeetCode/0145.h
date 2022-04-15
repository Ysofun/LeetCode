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
	void Postorder(vector<int>& ret, TreeNode* root)
	{
		if (!root)
		{
			return;
		}

		Postorder(ret, root->left);
		Postorder(ret, root->right);
		ret.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		Postorder(ret, root);
		return ret;
	}
};