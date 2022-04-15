#pragma once
#include <cstddef>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* p = head;
		ListNode* q = head;
		while (k > 1 && q != nullptr)
		{
			q = q->next;
			k--;
		}
		if (q == nullptr) return head;
		while (q->next != nullptr)
		{
			p = p->next;
			q = q->next;
		}
		return p;
	}
};