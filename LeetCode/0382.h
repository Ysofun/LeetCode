#pragma once

#include <random>


class Solution {
public:

	ListNode* head;

	Solution(ListNode* head) {
		this->head = head;
	}

	int getRandom() {
		int i = 1, ans = 0;
		for (ListNode* node = head; node; node = node->next)
		{
			if (rand() % i == 0)
			{
				ans = node->val;
			}
			i++;
		}
		return ans;
	}
};
