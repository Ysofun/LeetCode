#pragma once
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* FindPre(Node* root)
    {
        while (root->right)
        {
            root = root->right;
        }
        return root;
    }
    Node* FindPost(Node* root)
    {
        while (root->left)
        {
            root = root->left;
        }
        return root;
    }
    void TurnTreeToList(Node* root)
    {
        if (!root->left && !root->right)
        {
            return;
        }
        if (root->left)
        {
            TurnTreeToList(root->left);
            Node* temp = FindPre(root->left);
            temp->right = root;
            root->left = temp;
        }
        if (root->right)
        {
            TurnTreeToList(root->right);
            Node* temp = FindPost(root->right);
            temp->left = root;
            root->right = temp;
        }
    }
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        TurnTreeToList(root);
        Node* p = root;
        Node* q = root;
        while (p->left)
        {
            p = p->left;
        }
        while (q->right)
        {
            q = q->right;
        }
        p->left = q;
        q->right = p;
        return p;
    }
};