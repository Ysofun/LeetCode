#pragma once



class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr)
		{
			return nullptr;
		}
		ListNode* pre1 = nullptr;
		ListNode* pre2 = nullptr;
		ListNode* idx = head;
		ListNode* head2 = head->next;

		while (idx != nullptr)
		{
			if (pre1 != nullptr)
			{
				pre1->next = idx;
			}
			if (pre2 != nullptr)
			{
				pre2->next = idx->next;
			}

			if (idx->next == nullptr)
			{
				pre1 = idx;
				break;
			}

			pre1 = idx;
			pre2 = idx->next;
			idx = idx->next->next;
		}

		pre1->next = head2;
		return head;
	}
};