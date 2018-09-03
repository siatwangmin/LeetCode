#include <iostream>
#include "linklist.h"

using namespace std;

//-------------------------------------------------------------------------------
//
//Given a list, rotate the list to the right by k places, where k is non-negative.
//
//For example:
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.
//
//-------------------------------------------------------------------------------


class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return head;

		int len = 0;
		ListNode* cur = head;
		ListNode* pre = NULL;
		ListNode* next = NULL;

		while (cur != NULL)
		{
			pre = cur;
			cur = cur->next;
			len++;
		}
		pre->next = head;

		cur = head;
		for (int i = 1; i < (len - (k % len)); i++)
		{
			cur = cur->next;
		}
		next = cur->next;
		cur->next = NULL;
		return next;
	}
};



class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4= new ListNode(4);
		ListNode* a5 = new ListNode(5);

		a1->next = a2;
		a2->next = a3;
		a3->next = a4;
		a4->next = a5;

		return a1;
	}
};