#pragma once
#include <cstddef>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head->val == val)
		{
			return head->next;
		}
		ListNode* p = head->next;
		ListNode* q = head;
		while (p != nullptr)
		{
			if (p->val == val)
			{
				q->next = p->next;
				break;
			}
			q = p;
			p = p->next;
		}
		return head;
	}
};