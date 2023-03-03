#pragma once
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* hair = new ListNode();
		ListNode* head = hair;
		while (list1 != nullptr && list2 != nullptr)
		{
			if (list1->val <= list2->val)
			{
				head->next = list1;
				list1 = list1->next;
			}
			else
			{
				head->next = list2;
				list2 = list2->next;
			}
			head = head->next;
		}

		head->next = list1 != nullptr ? list1 : list2;
		return hair->next;
	}
};