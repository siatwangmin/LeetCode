#include <iostream>
#include "linklist.h"

using namespace std;


//--------------------------------------------Description---------------------------
//Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//For example:
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note:
//Given m, n satisfy the following condition:
//1 ¡Ü m ¡Ü n ¡Ü length of list.
//---------------------------------------------------------------------------------

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* l1start = new ListNode(0);
		ListNode* l1end = l1start;
		ListNode* l2start = new ListNode(0);
		ListNode* l2end = new ListNode(0);
		l2start->next = l2end;
		ListNode* l3start = new ListNode(0);
		ListNode* l3end = l3start;
		ListNode* cur = head;
		ListNode* next = NULL;
		int count = 1;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = NULL;
			if (count < m)
			{
				l1end->next = cur;
				l1end = l1end->next;
			}
			else if (m <= count && count <= n)
			{
				if (count == m)
				{
					l2end->val = cur->val;
					l2end->next = cur->next;
				}
				else
				{
					cur->next = l2start->next;
					l2start->next = cur;
				}
			}
			else if (count > n)
			{
				l3end->next = cur;
				l3end = l3end->next;
			}
			cur = next;
			count++;
		}
		if (l3start->next != NULL)
		{
			l2end->next = l3start->next;
		}
		
		if (l1start != l1end)
		{
			l1end->next = l2start->next;
			return l1start->next;
		}
		else
		{
			return l2start->next;
		}
	}
};


class TestClass{
public:
	ListNode* GetTestData1(){
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

	ListNode* GetTestData2(){
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);
		ListNode* a5 = new ListNode(5);
		return a5;
	}
};