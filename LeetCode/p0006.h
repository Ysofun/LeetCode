#pragma once
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	stack<int> m_Stack;
	vector<int> m_Vector;
public:
    vector<int> reversePrint(ListNode* head) {
		while (head != NULL)
		{
			m_Stack.push(head->val);
			head = head->next;
		}
		while (!m_Stack.empty())
		{
			m_Vector.push_back(m_Stack.top());
			m_Stack.pop();
		}
		return m_Vector;
    }
};