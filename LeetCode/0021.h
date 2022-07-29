#pragma once



class Solution {
public:
	/*ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

		if (list1 == nullptr)
		{
			return list2;
		}
		if (list2 == nullptr)
		{
			return list1;
		}

		ListNode* head = list1->val <= list2->val ? list1 : list2;

		ListNode* pre = nullptr;
		while (list1 != nullptr && list2 != nullptr)
		{
			ListNode* temp = list2->next;
			if (list1->val <= list2->val)
			{
				while (list1 != nullptr && list1->val <= list2->val)
				{
					pre = list1;
					list1 = list1->next;
				}
				pre->next = list2;
				if (list1 == nullptr)
				{
					break;
				}
				list2->next = list1;

				pre = list2;
				list2 = temp;
			}
			else
			{
				if (pre != nullptr)
				{
					pre->next = list2;
				}
				list2->next = list1;

				pre = list2;
				list2 = temp;
			}
		}

		return head;
	}*/

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* preHead = new ListNode(-1);
		ListNode* pre = preHead;

		while (list1 != nullptr && list2 != nullptr)
		{
			if (list1->val < list2->val)
			{
				pre->next = list1;
				list1 = list1->next;
			}
			else
			{
				pre->next = list2;
				list2 = list2->next;
			}
			pre = pre->next;
		}

		pre->next = list1 == nullptr ? list2 : list1;
		return preHead->next;
	}
};