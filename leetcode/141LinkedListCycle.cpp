#include <iostream>
#include <set>
#include "linklist.h"


using namespace std;

//**************   Description   ************************
//Given a linked list, determine if it has a cycle in it.
//
//Follow up:
//Can you solve it without using extra space?
//******************************************************

//方法一：用到了额外空间,56ms 使用set里面涉及到查找，所以整个算法会相对来说会很慢
//class Solution {
//public:
//	bool hasCycle(ListNode *head) {
//		set<ListNode*> s;
//		ListNode* cur = head;
//
//		while (cur != NULL)
//		{
//			if (s.find(cur) == s.end())
//			{
//				s.insert(cur);
//			}
//			else
//			{
//				return true;
//			}
//			cur = cur->next;
//		}
//		return false;
//	}
//};

//方法二：12ms
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* start = head;
		ListNode* end = head;
		if (start == NULL || start->next == NULL)
			return false;
		while (end->next != NULL && end->next->next != NULL)
		{
			start = start->next;
			end = end->next->next;
			if (start == end)
				return true;
		}
		return false;
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
		a5->next = a6;

		return a1;
	}
};