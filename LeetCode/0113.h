#pragma once
#include <vector>
#include <iostream>
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
	int sum = 0, cnt = 0;
	int targetSum;
	void GetSum(vector<vector<int>>& ret, TreeNode* root)
	{
		/*
		cout << "cnt: " << cnt << endl;
		for (auto& vs : ret)
		{
			for (auto& v : vs)
			{
				cout << "v: " << v << ' ';
			}
			cout << endl;
		}
		*/
		if (!root->left && !root->right)
		{
			sum += root->val;
			ret[cnt].push_back(root->val);
			if (sum == targetSum)
			{
				cnt++;
				cout << "Find Answer" << endl;
				ret.push_back(ret[cnt - 1]);
				cout << "Copy Complete" << endl;
			}
			sum -= root->val;
			ret[cnt].pop_back();
			return;
		}
		sum += root->val;
		ret[cnt].push_back(root->val);
		if (root->left) GetSum(ret, root->left);
		if (root->right) GetSum(ret, root->right);
		sum -= root->val;
		ret[cnt].pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		if (!root)
		{
			return {};
		}
		vector<vector<int>> ret;
		this->targetSum = targetSum;
		ret.push_back({});
		GetSum(ret, root);
		if (ret.back().empty())
		{
			ret.pop_back();
		}
		return ret;
	}
};