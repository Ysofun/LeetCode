#pragma once



class Solution {
public:

	ListNode* sortList(ListNode* head, ListNode* tail)
	{
		if (head == nullptr)
		{
			return nullptr;
		}

		if (head->next == tail)
		{
			head->next = nullptr;
			return head;
		}

		ListNode* slow = head;
		ListNode* fast = head;

		while (fast != tail && fast->next != tail)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		return Merge(sortList(head, slow), sortList(slow, tail));
	}

	ListNode* Merge(ListNode* head1, ListNode* head2)
	{
		ListNode* preHead = new ListNode(0);
		ListNode* pre = preHead;

		while (head1 != nullptr && head2 != nullptr)
		{
			if (head1->val <= head2->val)
			{
				pre->next = head1;
				head1 = head1->next;
			}
			else
			{
				pre->next = head2;
				head2 = head2->next;
			}
			pre = pre->next;
		}

		pre->next = head1 == nullptr ? head2 : head1;
		return preHead->next;
	}

	ListNode* sortList(ListNode* head) {
		return sortList(head, nullptr);
	}
};