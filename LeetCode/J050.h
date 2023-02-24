#pragma once
class Solution {
public:
    unordered_map<long long, int> m_PreSum;
    
    int pathSum(TreeNode* root, long long sum, int targetSum)
    {
        if (root == nullptr) { return 0; }

        int cnt = 0;
        sum += root->val;
        if (m_PreSum.count(sum - targetSum)) { cnt += m_PreSum[sum - targetSum]; }

        m_PreSum[sum]++;
        cnt += pathSum(root->left, sum, targetSum);
        cnt += pathSum(root->right, sum, targetSum);
        m_PreSum[sum]--;

        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        m_PreSum[0] = 1;
        return pathSum(root, 0, targetSum);
    }
};