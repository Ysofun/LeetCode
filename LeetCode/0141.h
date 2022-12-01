#pragma once
class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (!head) { return false; }

		ListNode* slow = head;
		ListNode* fast = head;
		do
		{
			slow = slow->next;
			fast = fast->next;
			if (!fast) { return false; }
			fast = fast->next;
		} while (slow != fast && slow != nullptr && fast != nullptr);

		return slow == fast && slow != nullptr;
	}
};