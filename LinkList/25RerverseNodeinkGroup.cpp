#include <iostream>
#include "linklist.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------
//
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5
//
//-------------------------------------------------------------------------------------------------------------------


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* h = new ListNode(0);
		ListNode* e = NULL;

		ListNode* cur = head;
		ListNode* next = NULL;
		int i = 0;
		for (; i < k; i++)
		{
			if (cur != NULL)
				cur = cur->next;
			else
			{
				return head;
			}
		}
		cur = head;
		if (i == k)
		{
			i = 0;
			for (; i < k; i++)
			{
				next = cur->next;
				cur->next = h->next;
				h->next = cur;
				if (e == NULL)
					e = cur;
				cur = next;
			}
		}

		e->next = reverseKGroup(cur,k);
		return h->next;
	}
};


class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);
		ListNode* a5 = new ListNode(5);

		a1->next = a2;
		a2->next = a3;
		a3->next = a4;
		a4->next = a5;
		return a1;
	}
};