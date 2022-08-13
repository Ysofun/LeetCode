#pragma once



class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int size = 0;
		ListNode* headNew = head;

		while (headNew != nullptr)
		{
			size++;
			headNew = headNew->next;
		}

		size -= n;
		headNew = head;
		ListNode* pre = nullptr;
		for (int i = 0; i < size && headNew != nullptr; i++)
		{
			pre = headNew;
			headNew = headNew->next;
		}
		if (pre == nullptr)
		{
			head = headNew->next;
		}
		else
		{
			pre->next = headNew->next;
		}
		return head;
	}
};