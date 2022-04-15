#pragma once
#include <cstddef>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* hair = new ListNode(0);
		ListNode* pre = nullptr;
		hair->next = head;
		while (l1 != nullptr || l2 != nullptr)
		{
			if (l1 == nullptr)
			{
				while (l2 != nullptr)
				{
					int sum = head->val + l2->val;
					head->val = sum % 10;
					head->next = new ListNode(sum / 10);
					l2 = l2->next;
					pre = head;
					head = head->next;
				}
				break;
			}
			if (l2 == nullptr)
			{
				while (l1 != nullptr)
				{
					int sum = head->val + l1->val;
					head->val = sum % 10;
					head->next = new ListNode(sum / 10);
					l1 = l1->next;
					pre = head;
					head = head->next;
				}
				break;
			}
			int temp = l1->val + l2->val + head->val;
			head->val = (temp) % 10;
			head->next = new ListNode(temp / 10);
			l1 = l1->next;
			l2 = l2->next;
			pre = head;
			head = head->next;
		}
		if (head->val == 0)
		{
			if (pre) pre->next = nullptr;
			delete head;
		}
		return hair->next;
	}
};