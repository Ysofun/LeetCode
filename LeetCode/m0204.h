#pragma once
#include <cstddef>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		bool flag = false;
		ListNode* temp = nullptr;
		ListNode* preTemp = nullptr;
		ListNode* hair = new ListNode(0);
		hair->next = head;
		for (ListNode* p = head; p != nullptr; p = p->next)
		{
			if (p->val >= x)
			{
				temp = p;
				break;
			}
			preTemp = p;
		}
		if (temp == nullptr) return head;
		if (preTemp == nullptr)
		{
			flag = true;
			preTemp = new ListNode(0);
			preTemp->next = temp;
		}
		ListNode* pre;
		for (ListNode* p = temp; p != nullptr; p = p->next)
		{
			if (p->val < x)
			{
				if (pre) pre->next = p->next;
				preTemp->next = p;
				p->next = temp;
				preTemp = p;
				if (flag)
				{
					hair->next = p;
					flag = false;
				}
			}
			pre = p;
		}
		return hair->next;
    }
};