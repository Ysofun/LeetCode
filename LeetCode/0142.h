#pragma once



class Solution {
public:
	/*ListNode* detectCycle(ListNode* head) {

		while (head != nullptr)
		{
			ListNode* SlowPtr = head->next;

			if (head->next == nullptr)
			{
				return nullptr;
			}
			ListNode* FastPtr = head->next->next;

			while (SlowPtr != FastPtr)
			{
				if (FastPtr == nullptr || FastPtr->next == nullptr)
				{
					return nullptr;
				}

				SlowPtr = SlowPtr->next;
				FastPtr = FastPtr->next->next;
			}

			if (SlowPtr == head)
			{
				return head;
			}

			head = head->next;
		}

		return nullptr;
	}*/


	ListNode* detectCycle(ListNode* head)
	{
		ListNode* SlowPtr = head;
		ListNode* FastPtr = head;

		while (FastPtr != nullptr && FastPtr->next != nullptr)
		{
			SlowPtr = SlowPtr->next;
			FastPtr = FastPtr->next->next;

			if (SlowPtr == FastPtr)
			{
				ListNode* ptr = head;
				while (ptr != SlowPtr)
				{
					SlowPtr = SlowPtr->next;
					ptr = ptr->next;
				}

				return ptr;
			}
		}

		return nullptr;
	}
};