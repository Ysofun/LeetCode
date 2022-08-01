#pragma once



class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {

		vector<vector<int>> ans;
		if (root == nullptr)
		{
			return ans;
		}

		queue<TreeNode*> q;
		q.emplace(root);

		while (!q.empty())
		{
			vector<int> temp;

			for (int i = q.size() - 1; i >= 0; i--)
			{
				TreeNode* TempNode = q.front();
				q.pop();
				temp.emplace_back(TempNode->val);

				if (TempNode->left)
				{
					q.emplace(TempNode->left);
				}
				if (TempNode->right)
				{
					q.emplace(TempNode->right);
				}
			}

			ans.emplace_back(temp);
			temp.clear();
		}

		return ans;
	}
};