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
	int sum = 0, ans = 0;
	void GetSum(TreeNode* root)
	{
		if (!root->left && !root->right)
		{
			sum = sum * 10 + root->val;
			ans += sum;
			sum = (sum - root->val) / 10;
			return;
		}
		sum = sum * 10 + root->val;
		if (root->left) GetSum(root->left);
		if (root->right) GetSum(root->right);
		sum = (sum - root->val) / 10;
	}

    int sumNumbers(TreeNode* root) {
		GetSum(root);
		return ans;
    }
};