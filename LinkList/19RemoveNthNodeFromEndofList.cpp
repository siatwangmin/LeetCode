#include <iostream>
#include <vector>
#include "linklist.h"

using namespace std;

//***********************   Description  *******************************************
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//   Given linked list: 1->2->3->4->5, and n = 2.
//
//   After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//Given n will always be valid.
//Try to do this in one pass.
//**********************************************************************************

////方法一
//class Solution {	
//public:
//	ListNode* removeNthFromEnd(ListNode* head, int n) {
//		ListNode* cur = head;
//		vector<ListNode*> vec;
//		while (cur != NULL)
//		{
//			vec.push_back(cur);
//			cur = cur->next;
//		}
//		if (vec[vec.size() - n] == head)
//		{
//			head = head->next;
//		}
//		int indx = vec.size() - n - 1;
//		if (indx > -1)
//		{
//			vec[vec.size() - n - 1]->next = vec[vec.size() - n]->next;
//		}
//		delete vec[vec.size() - n];
//		return head;
//	}
//};


//方法二：
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* start = head;
		ListNode* end = head;
		int i = 0;
		for (i = 0; i < n + 1; i++)
		{
			if (end == NULL)
			{
				break;
			}
			end = end->next;
		}
		while (end != NULL)
		{
			start = start->next;
			end = end->next;
		}

		if (i < n + 1 && start == head)
		{
			head = head->next;
		}
		else
		{
			start->next = start->next->next;
		}
		return head;
	}
};




class TestClass{
public:
	ListNode* GetTestData()
	{
		ListNode* node1 = new ListNode(1);
		ListNode* node2 = new ListNode(2);
		ListNode* node3 = new ListNode(3);
		ListNode* node4 = new ListNode(4);
		ListNode* node5 = new ListNode(5);

		node1->next = node2;
		node2->next = node3;
		node3->next = node4;
		node4->next = node5;

		return node1;
	}
};