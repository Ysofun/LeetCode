#pragma once
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* hair = new ListNode(0);
		hair->next = l1;
		
		int plus = 0;
		ListNode* pre = hair;
		while (l1 != nullptr && l2 != nullptr)
		{
			int sum = l1->val + l2->val + plus;
			l1->val = sum % 10;
			plus = sum / 10;
			pre = l1;
			l1 = l1->next;
			l2 = l2->next;
		}

		if (l1 != nullptr)
		{
			while (l1 != nullptr && plus == 1)
			{
				int sum = l1->val + plus;
				l1->val = sum % 10;
				plus = sum / 10;
				pre = l1;
				l1 = l1->next;
			}
		}
		if (l2 != nullptr)
		{
			pre->next = l2;
			while (l2 != nullptr && plus == 1)
			{
				int sum = l2->val + plus;
				l2->val = sum % 10;
				plus = sum / 10;
				pre = l2;
				l2 = l2->next;
			}
		}
		if (l1 == nullptr && l2 == nullptr && plus == 1) { pre->next = new ListNode(1); }
		return hair->next;
	}
};