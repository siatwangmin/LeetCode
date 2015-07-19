#include <iostream>
#include <set>
#include "linklist.h"

using namespace std;


//***************************************      Description    *********************************
//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//Follow up:
//Can you solve it without using extra space?
//*********************************************************************************************

//方法一：直观的解法 56ms
//class Solution {
//public:
//	ListNode *detectCycle(ListNode *head) {
//		ListNode* cur = head;
//		set<ListNode*> s;
//		while (cur != NULL)
//		{
//			if (s.find(cur) != s.end())
//			{
//				break;
//			}
//			s.insert(cur);
//			cur = cur->next;
//		}
//		return cur;
//	}
//};


class Solution {
public:
	ListNode *detectCycle(ListNode *head) {

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
		ListNode* a6 = new ListNode(6);

		a1->next = a2;
		a2->next = a3;
		a3->next = a4;
		a4->next = a5;
		a5->next = a6;
		a6->next = a4;

		return a1;
	}

	ListNode* GetTestData2()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);
		ListNode* a5 = new ListNode(5);
		ListNode* a6 = new ListNode(6);

		a1->next = a2;
		a2->next = a3;
		a3->next = a4;
		a4->next = a5;
		a5->next = a6;
		a6->next = a1;

		return a1;
	}

	ListNode* GetTestData3()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);
		ListNode* a5 = new ListNode(5);
		ListNode* a6 = new ListNode(6);

		a1->next = a2;
		a2->next = a3;
		a3->next = a4;
		a4->next = a5;
		a5->next = a5;

		return a1;
	}
};