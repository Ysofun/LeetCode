#pragma once
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	queue<TreeNode*> m_BFSOrder;
	vector<vector<int>> m_TreeOrder;
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr)
		{
			return {};
		}
		m_BFSOrder.push(root);
		while (!m_BFSOrder.empty())
		{
			vector<int> tempOrder;
			for (int i = m_BFSOrder.size(); i > 0; i--)
			{
				TreeNode* temp = m_BFSOrder.front();
				m_BFSOrder.pop();
				tempOrder.push_back(temp->val);
				if (temp->left) m_BFSOrder.push(temp->left);
				if (temp->right) m_BFSOrder.push(temp->right);
			}
			m_TreeOrder.push_back(tempOrder);
			tempOrder.clear();
		}
		for (int i = 0; i < m_TreeOrder.size(); i++)
		{
			if (i % 2 != 0)
			{
				reverse(m_TreeOrder[i].begin(), m_TreeOrder[i].end());
			}
		}
		return m_TreeOrder;
	}
};