#include <iostream>
#include "linklist.h"

using namespace std;

//---------------------------------------Description------------------------------------------
//Given a linked list and a value x, partition it such that all nodes less than x come before 
//nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.
//-------------------------------------------------------------------------------------------

//±©Á¦½â·¨£¬Time Out
//class Solution {
//public:
//	ListNode* partition(ListNode* head, int x) {
//		ListNode* cur = head;
//		ListNode* start = NULL;
//		ListNode* pre = NULL;
//		ListNode* lPre = NULL;
//		ListNode* myNode = NULL;
//		while (cur != NULL)
//		{
//			if (cur->val == x)
//			{
//				myNode = cur;
//				break;
//			}
//			cur = cur->next;
//		}
//
//		while (cur != NULL)
//		{
//			if (cur->val < x)
//			{
//				pre->next = cur->next;
//				start = head;
//				while (start!=myNode->next)
//				{
//					if (start->val > cur->val)
//					{
//						if (lPre != NULL)
//							lPre->next = cur;
//						cur->next = start;
//						break;
//					}
//					lPre = start;
//					start = start->next;
//				}
//			}
//			pre = cur;
//			cur = cur->next;
//		}
//
//		return head;
//	}
//};

class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		if (head == NULL)
			return head;

		ListNode *sm = new ListNode(0), *sm_tail = sm;
		ListNode *bg = new ListNode(0), *bg_tail = bg;
		ListNode *cur = head;

		while (cur) {
			if (cur->val < x) {
				sm_tail->next = cur;
				cur = cur->next;
				sm_tail = sm_tail->next;
				sm_tail->next = NULL;
			}
			else{
				bg_tail->next = cur;
				bg_tail = bg_tail->next;
				cur = cur->next;
				bg_tail->next = NULL;
			}
		}
		sm_tail->next = bg->next;
		return sm->next;
	}
};

class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a2_1 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);
		ListNode* a5 = new ListNode(5);

		a1->next = a4;
		a4->next = a3;
		a3->next = a2;
		a2->next = a5;
		a5->next = a2_1;
		return a1;
	}
};