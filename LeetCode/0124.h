class Solution {
public:
	int DFS(TreeNode* root, int& ans)
	{
		if (root == nullptr) { return 0; }
		int lsum = DFS(root->left, ans);
		int rsum = DFS(root->right, ans);

		int maxSum = max(max(lsum, rsum) + root->val, root->val);
		ans = max(ans, max(maxSum, lsum + rsum + root->val));
		return maxSum;
	}
	int maxPathSum(TreeNode* root) {
		int ans = INT_MIN;
		DFS(root, ans);
		return ans;
	}
};