#pragma once


class Solution {
public:
	int numComponents(ListNode* head, vector<int>& nums) {
		map<int, bool> numsMap;
		for (int i = 0; i < nums.size(); i++)
		{
			numsMap[nums[i]] = true;
		}

		int ans = 0, len = 0;
		while (head != nullptr)
		{
			if (numsMap.find(head->val) != numsMap.end())
			{
				len++;
			}
			else
			{
				ans = ans + (len > 0 ? 1 : 0);
				len = 0;
			}
			head = head->next;
		}

		return ans + (len > 0 ? 1 : 0);
	}
};