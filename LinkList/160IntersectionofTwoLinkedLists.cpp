#include <iostream>
#include <stack>
#include <set>
#include "linklist.h"

using namespace std;

//***************************************    Description  *************************************
//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists:
//
//A:          a1 → a2
//                   ↘
//                     c1 → c2 → c3
//                   ↗            
//B:     b1 → b2 → b3
//begin to intersect at node c1.
//
//
//Notes:
//
//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.
//**********************************************************************************************

//方法一：最直观的想法，用hash，耗时116ms，最小的时间需要52ms 甚至更小
//class Solution {
//public:
//	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//		set<ListNode*> s;
//		ListNode* curA = headA;
//		ListNode* curB = headB;
//
//		while (curA != NULL)
//		{
//			s.insert(curA);
//			curA = curA->next;
//		}
//
//		while (s.find(curB) == s.end() && curB != NULL)
//		{
//			curB = curB->next;
//		}
//
//		return curB;
//	}
//};


//方法二，用stack
//

//方法三：
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* curA = headA;
		ListNode* curB = headB;
		while (curA != curB)
		{
			curA = curA ? curA->next : headB;
			curB = curB ? curB->next : headA;
		}
		return curA;
	}
};



class TestClass{
private:
	ListNode* c;
public:
	TestClass()
	{
		c = new ListNode(7);
		c->next = new ListNode(8);
		c->next->next = new ListNode(9);
	}
	ListNode* GetTestData1()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);

		a1->next = a2;

		a2->next = c;

		return a1;
	}

	ListNode* GetTestData2()
	{
		ListNode* b4 = new ListNode(4);
		ListNode* b5 = new ListNode(5);
		ListNode* b6 = new ListNode(6);

		b4->next = b5;
		b5->next = b6;
		b6->next = c;

		return b4;
	}
};