#pragma once
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) { return nullptr; }
		ListNode* hair = new ListNode(0);
		hair->next = head;

		ListNode* pre = hair;
		ListNode* newHead = head;
		head = head->next;
		int sum = 0;
		while (head != nullptr)
		{
			if (head->val == newHead->val) { sum++; }
			if (head->val != newHead->val)
			{
				if (sum == 0)
				{
					newHead->next = head;
					pre = newHead;
					newHead = newHead->next;
				}
				else
				{
					pre->next = head;
					newHead = head;
					sum = 0;
				}
			}
			head = head->next;
		}

		if (sum != 0) { pre->next = nullptr; }
		return hair->next;
	}
};