class Solution {
public:

	ListNode* Sort(ListNode* head, ListNode* tail)
	{
		if (head == nullptr) { return nullptr; }
		if (head->next == tail)
		{
			head->next = nullptr;
			return head;
		}

		ListNode* slow = head;
		ListNode* fast = head;
		do 
		{
			slow = slow->next;
			fast = fast->next->next;
		} while (fast != tail && fast->next != tail);

		return merge(Sort(head, slow), Sort(slow, tail));
	}

	ListNode* merge(ListNode* left, ListNode* right)
	{
		ListNode* hair = new ListNode(0);
		ListNode* head = hair;
		while (left != nullptr && right != nullptr)
		{
			if (left->val < right->val)
			{
				head->next = left;
				left = left->next;
			}
			else
			{
				head->next = right;
				right = right->next;
			}
			head = head->next;
		}
		
		if (left != nullptr) { head->next = left; }
		else if (right != nullptr) { head->next = right; }
		return hair->next;
	}

	ListNode* sortList(ListNode* head) {
		return Sort(head, nullptr);
	}
};