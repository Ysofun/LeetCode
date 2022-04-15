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
	void FindSum(vector<int>& temp, vector<vector<int>>& m_Ans, TreeNode* root, int sum, int target)
	{
		if (!root->left && !root->right)
		{
			sum += root->val;
			if (sum == target)
			{
				temp.push_back(root->val);
				m_Ans.push_back(temp);
				temp.pop_back();
				return;
			}
		}
		temp.push_back(root->val);
		if (root->left) FindSum(temp, m_Ans, root->left, sum + root->val, target);
		if (root->right) FindSum(temp, m_Ans, root->right, sum + root->val, target);
		temp.pop_back();
		return;
	}
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		if (!root) return {};
		vector<int> temp;
		vector<vector<int>> m_Ans;
		FindSum(temp, m_Ans, root, 0, target);
		return m_Ans;
	}
};