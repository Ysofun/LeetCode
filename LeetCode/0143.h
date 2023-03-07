class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr) { return; }
		ListNode* slow = head;
		ListNode* fast = head;
		do 
		{
			if (fast->next == nullptr) { break; }
			slow = slow->next;
			fast = fast->next->next;
		} while (fast != nullptr);

		ListNode* pre = nullptr;
		ListNode* next = nullptr;
		ListNode* begin = slow->next;
		while (begin != nullptr)
		{
			next = begin->next;
			begin->next = pre;
			pre = begin;
			begin = next;
		}
		slow->next = nullptr;

		ListNode* next2 = nullptr;
		while (pre != nullptr)
		{
			next = head->next;
			next2 = pre->next;
			head->next = pre;
			pre->next = next;
			head = next;
			pre = next2;
		}
	}
};