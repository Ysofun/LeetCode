#pragma once



class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* SlowPtr = head;
		ListNode* FastPtr = head;

		while (SlowPtr != nullptr && FastPtr != nullptr)
		{
			if (FastPtr->next == nullptr)
			{
				return SlowPtr;
			}

			FastPtr = FastPtr->next->next;
			SlowPtr = SlowPtr->next;
		}

		return SlowPtr;
	}
};