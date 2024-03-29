#pragma once
class Solution {
public:
    void dfs(TreeNode* root, int& pre, int& ans)
    {
        if (root == nullptr) { return; }
        dfs(root->left, pre, ans);
        if (pre == -1) { pre = root->val; }
        else
        {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }
    int minDiffInBST(TreeNode* root) {
        int pre = -1;
        int ans = 1000000;
        dfs(root, pre, ans);
        return ans;
    }
};