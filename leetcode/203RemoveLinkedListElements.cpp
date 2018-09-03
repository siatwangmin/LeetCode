#include <iostream>
#include "linklist.h"

using namespace std;

//*******************************   Description ***************************
//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5
//*************************************************************************

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* cur = head;
		ListNode* pre = NULL;
		ListNode* temp = NULL;
		while (cur != NULL)
		{
			if (cur->val == val)
			{
				temp = cur;
				if (pre != NULL)
				{
					pre->next = cur->next;
				}
				if (cur == head)
				{
					head = head->next;
				}
			}
			else
			{
				pre = cur;
			}
			cur = cur->next;
			if (temp != NULL)
			{
				delete temp;
				temp = NULL;
			}
		}
		return head;
	}
};


class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* node1 = new ListNode(1);
		ListNode* node1_2 = new ListNode(1);
		ListNode* node1_3 = new ListNode(1);
		
		node1->next = node1_2;
		node1_2->next = node1_3;

		return node1;
	}

	ListNode* GetTestData2()
	{
		ListNode* node1 = new ListNode(1);
		ListNode* node2 = new ListNode(2);
		ListNode* node3 = new ListNode(3);
		ListNode* node4 = new ListNode(4);
		ListNode* node5 = new ListNode(5);
		ListNode* node6 = new ListNode(6);

		node1->next = node2;
		node2->next = node3;
		node3->next = node4;
		node4->next = node5;
		node5->next = node6;

		return node1;
	}


};