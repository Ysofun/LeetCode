#pragma once
#include <cstddef>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		if (!l1 && !l2) return nullptr;
		ListNode* head;
		ListNode* p;
		if (l1->val < l2->val)
		{
			head = new ListNode(l1->val);
			l1 = l1->next;
		}
		else
		{
			head = new ListNode(l2->val);
			l2 = l2->next;
		}
		p = head;
		while (l1 || l2)
		{
			if (!l1 && l2)
			{
				while (l2)
				{
					head->next = new ListNode(l2->val);
					l2 = l2->next;
					head = head->next;
				}
				break;
			}
			if (l1 && !l2)
			{
				while (l1)
				{
					head->next = new ListNode(l1->val);
					l1 = l1->next;
					head = head->next;
				}
				break;
			}
			if (l1->val < l2->val)
			{
				head->next = new ListNode(l1->val);
				l1 = l1->next;
				head = head->next;
			}
			else
			{
				head->next = new ListNode(l2->val);
				l2 = l2->next;
				head = head->next;
			}
		}
		return p;
	}
};