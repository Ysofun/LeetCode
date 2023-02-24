#pragma once

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
        {
            return "[]";
        }
        string ans;
        queue<TreeNode*> BFS_QUE;
        BFS_QUE.push(root);
        ans.push_back('[');
        ans += to_string(root->val);
        while (!BFS_QUE.empty())
        {
            for (int i = 0; i < BFS_QUE.size(); i++)
            {
                TreeNode* temp = BFS_QUE.front();
                BFS_QUE.pop();

                ans.push_back(',');
                if (temp->left != nullptr)
                {
                    ans += to_string(temp->left->val);
                    BFS_QUE.push(temp->left);
                }
                else
                {
                    ans += "null";
                }

                ans.push_back(',');
                if (temp->right != nullptr)
                {
                    ans += to_string(temp->right->val);
                    BFS_QUE.push(temp->right);
                }
                else
                {
                    ans += "null";
                }
            }
        }

        int i = ans.length() - 1;
        while (ans[i] > '9' || ans[i] < '0')
        {
            i--;
            ans.pop_back();
        }
        ans.push_back(']');
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> Father_QUE;
        TreeNode* root = nullptr;
        int son_loc = 1;
        for (int i = 1; i < data.length() - 1; i++)
        {
            if (data[i] == 'n')
            {
                i = i + 4;
                if (son_loc == 1) { Father_QUE.pop(); }
            }
            else
            {
                int mul = 1;
                if (data[i] == '-') 
                { 
                    mul = -1;
                    i++;
                }
                int val = 0;
                while (data[i] != ',' && data[i] != ']')
                {
                    val = val * 10 + data[i] - '0';
                    i++;
                }
                val = val * mul;
                
                TreeNode* temp = new TreeNode(val);
                if (Father_QUE.empty()) { root = temp; }
                else
                {
                    if (son_loc == 0) { Father_QUE.front()->left = temp; }
                    else
                    {
                        Father_QUE.front()->right = temp;
                        Father_QUE.pop();
                    }
                }
                Father_QUE.push(temp);
            }
            son_loc = (son_loc + 1) % 2;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));