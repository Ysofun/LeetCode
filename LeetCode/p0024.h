#pragma once
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
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
		{
			return NULL;
		}
		while (head != NULL)
		{
			m_Stack.push(head->val);
			head = head->next;
		}

		ListNode* m_ListHead = new ListNode(m_Stack.top());
		ListNode* m_List = m_ListHead;
		m_Stack.pop();

		while (!m_Stack.empty())
		{
			m_List->next = new ListNode(m_Stack.top());
			m_List = m_List->next;
			m_Stack.pop();
		}
		return m_ListHead;
	}
};