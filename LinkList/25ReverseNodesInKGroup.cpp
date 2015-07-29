#include <iostream>
#include "linklist.h"

using namespace std;


//----------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* res = new ListNode(0);
		res->next = head;
		ListNode* cur = head;
		ListNode* next = NULL;
		ListNode* end = NULL;
		ListNode* start = NULL;
		int count = 1;
		while (cur != NULL)
		{
			start = cur;
			next = cur-> next;


			for (; count < k+1; count++)
			{
				next = cur->next;
				cur = next;
			}

			if (count == k + 1)
			{
				end = next;
				count = 1;
			}


			cur = next;
		}

	}
};