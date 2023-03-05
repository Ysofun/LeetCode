#pragma once
class Solution {
public:
	ListNode* mergeLists(ListNode* head1, ListNode* head2)
	{
		ListNode* hair = new ListNode();
		ListNode* newHead = hair;
		while (head1 != nullptr && head2 != nullptr)
		{
			if (head1->val < head2->val)
			{
				newHead->next = head1;
				head1 = head1->next;
			}
			else
			{
				newHead->next = head2;
				head2 = head2->next;
			}
			newHead = newHead->next;
		}

		if (head1 != nullptr) { newHead->next = head1; }
		if (head2 != nullptr) { newHead->next = head2; }
		return hair->next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r)
	{
		if (l > r) { return nullptr; }
		if (l == r) { return lists[l]; }
		int mid = l + ((r - l + 1) >> 1);
		return mergeLists(lists[mid], mergeLists(mergeKLists(lists, l, mid - 1), mergeKLists(lists, mid + 1, r)));
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) { return nullptr; }
		return mergeKLists(lists, 0, lists.size() - 1);
	}
};