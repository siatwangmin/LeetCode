#include <iostream>
#include "linklist.h"

using namespace std;

//*********************  Description  **********************************************
//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space. You may not modify the values in the 
//list, only nodes itself can be changed.
//**********************************************************************************

//·½·¨Ò»
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* first = head;
		ListNode* second = head;
		if (first == NULL || first->next == NULL)
			return first;
		else
		{
			second = head->next;
		}
		first->next = swapPairs(second->next);
		second->next = first;
		return second;
	}
};


class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* a1 =new ListNode(1);
		return a1;
	}

	ListNode* GetTestData2()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);

		a1->next = a2;
		a2->next = a3;
		a3->next = a4;
		return a1;
	}

	ListNode* GetTestData3()
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