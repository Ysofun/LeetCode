#pragma once
class Solution {
public:
	ListNode* reverseList(ListNode* head, int size)
	{
		ListNode* begin = head;
		ListNode* pre = nullptr;
		ListNode* next = nullptr;
		while (head != nullptr && size > 0)
		{
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
			size--;
		}
		if (head) { begin->next = next; }
		return pre;
	}

	ListNode* reverseBetween(ListNode* head, int left, int right) {
		int size = right - left + 1;
		ListNode* hair = new ListNode();
		hair->next = head;
		ListNode* pre = hair;
		while (head != nullptr)
		{
			if (--left == 0)
			{
				ListNode* begin = head;
				ListNode* reverseHead = reverseList(head, size);
				if (pre) { pre->next = reverseHead; }
				break;
			}
			pre = pre->next;
			head = head->next;
		}
		return hair->next;
	}
};