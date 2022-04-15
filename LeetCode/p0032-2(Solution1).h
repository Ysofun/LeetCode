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
	struct TreeNodeWithHeight
	{
		TreeNode* node;
		int height;
		TreeNodeWithHeight(TreeNode* _node, int _height) :node(_node), height(_height) {}
	};
	queue<TreeNodeWithHeight*> m_BFSOrder;
	vector<vector<int>> m_TreeOrder;
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr)
		{
			return {};
		}
		TreeNodeWithHeight* rootNew = new TreeNodeWithHeight(root, 0);
		m_BFSOrder.push(rootNew);
		while (!m_BFSOrder.empty())
		{
			TreeNodeWithHeight* temp = m_BFSOrder.front();
			m_BFSOrder.pop();
			if (temp->height > ((int)m_TreeOrder.size() - 1))
			{
				m_TreeOrder.push_back({ temp->node->val });
			}
			else
			{
				m_TreeOrder[temp->height].push_back(temp->node->val);
			}
			if (temp->node->left)
			{
				m_BFSOrder.push(new TreeNodeWithHeight(temp->node->left, temp->height + 1));
			}
			if (temp->node->right)
			{
				m_BFSOrder.push(new TreeNodeWithHeight(temp->node->right, temp->height + 1));
			}
		}
		return m_TreeOrder;
	}
};