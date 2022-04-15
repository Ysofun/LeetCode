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

	TreeNode* BuildTree(int left, int right, vector<int>& nums)
	{
		if (left > right)
		{
			return nullptr;
		}

		int mid = (left + right) >> 1;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = BuildTree(left, mid - 1, nums);
		root->right = BuildTree(mid + 1, right, nums);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return BuildTree(0, nums.size() - 1, nums);
	}
};