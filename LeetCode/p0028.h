#pragma once
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> m_BFSOrder;
		vector<vector<int>> m_TreeOrder;
		if (root == nullptr)
		{
			return true;
		}
		m_BFSOrder.push(root);
		while (!m_BFSOrder.empty())
		{
			vector<int> tempOrder;
			for (int i = m_BFSOrder.size(); i > 0; i--)
			{
				TreeNode* temp = m_BFSOrder.front();
				m_BFSOrder.pop();
				if (!temp)
				{
					tempOrder.push_back(-999);
				}
				else
				{
					tempOrder.push_back(temp->val);
					m_BFSOrder.push(temp->left);
					m_BFSOrder.push(temp->right);
				}
			}
			m_TreeOrder.push_back(tempOrder);
			tempOrder.clear();
		}

		for (int i = 0; i < m_TreeOrder.size(); i++)
		{
			vector<int> temp = m_TreeOrder[i];
			reverse(temp.begin(), temp.end());
			if (temp != m_TreeOrder[i])
			{
				return false;
			}
		}
		return true;
	}
};