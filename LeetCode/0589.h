#pragma once



class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:

	/*void PreOrder(vector<int>& TreePreOrder, Node* rootMirror)
	{
		if (rootMirror == nullptr)
		{
			return;
		}

		TreePreOrder.emplace_back(rootMirror->val);
		for (Node* child : rootMirror->children)
		{
			PreOrder(TreePreOrder, child);
		}
	}

	vector<int> preorder(Node* root) {
		vector<int> TreePreOrder;
		PreOrder(TreePreOrder, root);

		return TreePreOrder;
	}*/

	vector<int> preorder(Node* root)
	{

		vector<int> ans;
		if (root == nullptr)
		{
			return ans;
		}

		stack<Node*> st;
		st.emplace(root);
		while (!st.empty())
		{
			Node* SubRoot = st.top();
			st.pop();
			ans.emplace_back(SubRoot->val);

			for (int i = SubRoot->children.size() - 1; i >= 0; i--)
			{
				st.emplace(SubRoot->children[i]);
			}
		}

		return ans;
	}
};