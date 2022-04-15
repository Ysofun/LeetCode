#pragma once
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		int cntA = 0, cntB = 0;
		ListNode* p = headA;
		ListNode* q = headB;
		while (p)
		{
			cntA++;
			p = p->next;
		}
		while (q)
		{
			cntB++;
			q = q->next;
		}
		p = headA;
		q = headB;
		if (cntA > cntB)
		{
			while (cntA - cntB > 0 && p)
			{
				p = p->next;
				cntA--;
			}
			while (p && q && p != q)
			{
				p = p->next;
				q = q->next;
			}
		}
		else
		{
			while (cntB - cntA > 0 && q)
			{
				q = q->next;
				cntB--;
			}
			while (p && q && p != q)
			{
				p = p->next;
				q = q->next;
			}
		}
		if (!p || !q)
		{
			return nullptr;
		}
		else
		{
			return p;
		}
	}
};