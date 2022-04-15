#pragma once

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head, ListNode* tail)
	{
		ListNode* pre = nullptr;
		ListNode* curr = head;
		ListNode* next = tail->next;
		while (head != next)
		{
			head = head->next;
			curr->next = pre;
			pre = curr;
			curr = head;
		}
		return pre;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* headNew = nullptr;
		ListNode* hair = nullptr;
		while (head != nullptr)
		{
			ListNode* tail = head;
			ListNode* curr = head;
			for (int i = 0; i < k - 1; i++)
			{
				tail = tail->next;
				if (tail == nullptr) break;
			}
			if (tail == nullptr)
			{
				if (hair != nullptr) hair->next = curr;
				else return head;
				break;
			}
			head = tail->next;
			if (hair == nullptr) headNew = reverseList(curr, tail);
			else hair->next = reverseList(curr, tail);
			hair = curr;
		}
		return headNew;
	}
};