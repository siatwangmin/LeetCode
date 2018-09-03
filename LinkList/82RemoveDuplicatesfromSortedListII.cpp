#include <iostream>
#include <stack>
#include "linklist.h"

using namespace std;

//----------------------------------------------------------------------------
//
//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving
//only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.
//
//------------------------------------------------------------------------------

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* h = new ListNode(0);
		ListNode* h2 = new ListNode(0);

		h2->next = h;
		
		ListNode* cur = head;
		ListNode* next = NULL;
		ListNode* e = h;
		ListNode* p = h2;
		bool flag = false;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = NULL;

			if (e != h && e->val == cur->val)
			{
				flag = true;
			}
			else
			{
				if (flag)
				{
					p->next = NULL;
					e = p;
					e->next = cur;
					e = e->next;
					flag = false;
				}
				else
				{
					e->next = cur;
					p = e;
					e = e->next;
				}
			}

			cur = next;
		}

		if (flag)
		{
			p->next = NULL;
		}

		return h->next;
	}
};


class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3_1 = new ListNode(3);
		ListNode* a3_2 = new ListNode(3);
		ListNode* a4_1 = new ListNode(4);
		ListNode* a4_2 = new ListNode(4);
		ListNode* a5 = new ListNode(5);

		a1->next = a2;
		a2->next = a3_1;
		a3_1->next = a3_2;
		a3_2->next = a4_1;
		a4_1->next = a4_2;
		a4_2->next = a5;

		return a1;
	}

	ListNode* GetTestData2()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(1);
		ListNode* a3_1 = new ListNode(1);
		ListNode* a3_2 = new ListNode(1);
		ListNode* a4_1 = new ListNode(1);
		ListNode* a4_2 = new ListNode(1);
		ListNode* a5 = new ListNode(1);

		a1->next = a2;
		a2->next = a3_1;
		a3_1->next = a3_2;
		a3_2->next = a4_1;
		a4_1->next = a4_2;
		a4_2->next = a5;

		return a1;
	}
};