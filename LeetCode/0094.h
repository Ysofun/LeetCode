#pragma once
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> stk;
		while (root != nullptr || !stk.empty())
		{
			while (root != nullptr)
			{
				stk.push(root);
				root = root->left;
			}

			root = stk.top();
			stk.pop();
			ans.push_back(root->val);
			root = root->right;
		}
		return ans;
	}
};