#pragma once



class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;

		stack<int> stk;

		while (fast != nullptr && fast->next != nullptr)
		{
			stk.emplace(slow->val);
			slow = slow->next;
			fast = fast->next->next;
		}

		if (fast != nullptr)
		{
			slow = slow->next;
		}

		while (slow != nullptr && !stk.empty())
		{
			if (slow->val != stk.top())
			{
				return false;
			}
			stk.pop();
			slow = slow->next;
		}

		return true;
	}
};