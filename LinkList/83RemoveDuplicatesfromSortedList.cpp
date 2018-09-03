#include <iostream>
#include "linklist.h"

using namespace std;



//**********************************Description**********************************************
//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.
//*********************************************************************************************

//完美解法一，回收内存
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* cur = head;
		ListNode* temp = NULL;
		while (cur != NULL)
		{
			if (pre != NULL && pre->val == cur->val)
			{
				pre->next = cur->next;
				temp = cur;
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

//可能造成内存泄露
//class Solution {
//public:
//	ListNode* deleteDuplicates(ListNode* head) {
//		ListNode* pre = NULL;
//		ListNode* cur = head;
//		while (cur != NULL)
//		{
//			if (pre != NULL && pre->val == cur->val)
//			{
//				pre->next = cur->next;
//			}
//			else
//			{
//				pre = cur;
//			}
//			cur = cur->next;
//		}
//		return head;
//	}
//};


class TestClass{
public:
	ListNode* GetTestData()
	{
		ListNode* node1 = new ListNode(1);
		ListNode* node1_1 = new ListNode(1);
		ListNode* node2 = new ListNode(2);

		ListNode* node3 = new ListNode(3);
		ListNode* node3_1 = new ListNode(3);

		node1->next = node1_1;
		node1_1->next = node2;
		node2->next = node3;
		node3->next = node3_1;
		return node1;

	}
};