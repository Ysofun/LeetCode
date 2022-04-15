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
private:
	queue<TreeNode*> m_BFSOrder;
	vector<int> m_TreeOrder;
public:
	vector<int> Solution1(TreeNode* root)
	{
		if (root == nullptr)
		{
			return {};
		}
		m_BFSOrder.push(root);
		while (!m_BFSOrder.empty())
		{
			TreeNode* temp = m_BFSOrder.front();
			m_BFSOrder.pop();
			m_TreeOrder.push_back(temp->val);
			if (temp->left) m_BFSOrder.push(temp->left);
			if (temp->right) m_BFSOrder.push(temp->right);
		}
		return m_TreeOrder;
	}

	void Solution2(TreeNode* root)
	{
		TreeNode* temp = m_BFSOrder.front();
		m_BFSOrder.pop();
		m_TreeOrder.push_back(temp->val);
		if (temp->left) m_BFSOrder.push(temp->left);
		if (temp->right) m_BFSOrder.push(temp->right);

		if (!m_BFSOrder.empty())
		{
			Solution2(m_BFSOrder.front());
		}
	}

	vector<int> levelOrder(TreeNode* root) {
		if (!root)
		{
			return {};
		}
		m_BFSOrder.push(root);
		Solution2(root);
		return m_TreeOrder;
	}
};