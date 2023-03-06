class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == nullptr) { return nullptr; }
		ListNode* slow = head;
		ListNode* fast = head;
		do 
		{
			slow = slow->next;
			if (fast->next == nullptr) { return nullptr; }
			fast = fast->next->next;
		} while (slow != fast && fast != nullptr);
		
		if (fast == nullptr) { return nullptr; }
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};