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

//一个很有意思的解法
//http://fisherlei.blogspot.com/2013/11/leetcode-linked-list-cycle-ii-solution.html
//http://blog.csdn.net/cs_guoxiaozhu/article/details/14209743

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* S = head;
		ListNode* F = head;
		
		while (S != NULL && F != NULL)
		{
			S = S->next;
			F = F->next;
			if (F != NULL)
				F = F->next;
			if (S == F)
			{
				break;
			}
		}

		if (F == NULL)
			return F;

		S = head;

		while (F != S)
		{
			F = F->next;
			S = S->next;
		}
		return F;
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