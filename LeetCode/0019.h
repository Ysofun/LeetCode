#pragma once
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* hair = new ListNode(0, head);
		ListNode* slow = hair;
		ListNode* fast = head;
		for (int i = 0; i < n; i++) { fast = fast->next; }

		while (fast != nullptr)
		{
			slow = slow->next;
			fast = fast->next;
		}
		slow->next = slow->next->next;
		return hair->next;
	}
};