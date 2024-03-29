#pragma once

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* next = nullptr;

		while (head != nullptr)
		{
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}

		return pre;
	}
};