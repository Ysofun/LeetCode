#pragma once
#include <map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
  
class Solution {
private:
	map<TreeNode*, int> height;
	map<TreeNode*, TreeNode*> father;
public:

	TreeNode* FindLCA(TreeNode* p, TreeNode* q)
	{
		int temp1 = height[p], temp2 = height[q];
		while (temp1 != temp2)
		{
			if (temp1 > temp2)
			{
				temp1--;
				p = father[p];
			}
			else
			{
				temp2--;
				q = father[q];
			}
		}
		while (p != q)
		{
			p = father[p];
			q = father[q];
		}
		return p;
	}

	void SearchTree(TreeNode* root, TreeNode* fa)
	{
		if (!root) return;
		father.insert(pair<TreeNode*, TreeNode*>(root, fa));
		height.insert(pair<TreeNode*, int>(root, height[fa] + 1));
		SearchTree(root->left, root);
		SearchTree(root->right, root);
		return;
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		father.insert(pair<TreeNode*, TreeNode*>(root, root));
		height.insert(pair<TreeNode*, int>(root, 1));
		SearchTree(root->left, root);
		SearchTree(root->right, root);
		return FindLCA(p, q);
    }
};