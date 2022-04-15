#pragma once
#include <cstddef>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
		ListNode* p = head;
		ListNode* q = head;
		while (q != nullptr)
		{
			if (!q->next) return nullptr;
			p = p->next;
			q = q->next->next;
			if (p == q)
			{
				ListNode* ptr = head;
				while (ptr != p)
				{
					p = p->next;
					ptr = ptr->next;
				}
				return ptr;
			}
		}
		return nullptr;
    }
};