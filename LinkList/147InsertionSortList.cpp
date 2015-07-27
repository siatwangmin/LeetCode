#include<iostream>
#include "linklist.h"

using namespace std;

//-------------Description ---------------
//Sort a linked list using insertion sort.
//----------------------------------------


class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode* cur = head->next;
		ListNode* next = NULL;
		ListNode* res = new ListNode(0);
		res->next = head;
		ListNode* curRes = res->next;
		ListNode* pre = res;
		head->next = NULL;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = NULL;
			while (curRes != NULL)
			{
				if (curRes->val > cur->val)
				{
					pre->next = cur;
					cur->next = curRes;
					pre = res;
					curRes = res->next;
					break;
				}
				pre = curRes;
				curRes = curRes->next;
			}
			if (curRes == NULL)
			{
				pre->next = cur;
				pre = res;
				curRes = res->next;
			}
			cur = next;
		}

		return res->next;
	}
};


class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* a1 = new ListNode(1);
		return a1;
	}
	ListNode* GetTestData2()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);
		ListNode* a5 = new ListNode(5);

		a2->next = a1;
		a3->next = a2;
		a4->next = a3;
		a5->next = a4;

		return a5;
	}

	ListNode* GetTestData3()
	{
		ListNode* a6 = new ListNode(6);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);
		ListNode* a5 = new ListNode(5);

		a2->next = a6;
		a3->next = a2;
		a4->next = a3;
		a5->next = a4;

		return a5;
	}
};