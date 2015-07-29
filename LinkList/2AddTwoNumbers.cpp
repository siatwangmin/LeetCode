#include <iostream>
#include "linklist.h"

using namespace std;

//------------------------------------------------------------------------------------------------------------
//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order
//and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//------------------------------------------------------------------------------------------------------------

//方法一：迭代，这样算法有点复杂
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* curL1Length = l1;
		ListNode* curL2Length = l2;

		
		while (curL1Length != NULL  && curL2Length != NULL)
		{
			curL1Length = curL1Length->next;
			curL2Length = curL2Length->next;
		}

		ListNode* curL1 = curL1Length ? l1 : l2;
		ListNode* curL2 = curL1Length ? l2 : l1;

		ListNode* preL1 = NULL;
		ListNode* preL2 = NULL;
		int carry = 0;
		while (curL1 != NULL)
		{
			if (curL2 != NULL)
			{
				curL1->val += curL2->val + carry;
				preL2 = curL2;
				curL2 = curL2->next;
			}
			else
			{
				curL1->val += carry;
			}
			carry = curL1->val / 10;
			curL1->val = curL1->val % 10;

			preL1 = curL1;
			curL1 = curL1->next;		
		}

		if (carry != 0 && preL1 != NULL)
		{
			preL1->next = new ListNode(carry);
		}

		return curL1Length ? l1 : l2;
	}
};

class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* a1 = new ListNode(1);
		return a1;
	}
	ListNode* GetTestData2()
	{
		ListNode* a9_1 = new ListNode(9);
		ListNode* a9_2 = new ListNode(9);
		ListNode* a9_3 = new ListNode(9);
		ListNode* a9_4 = new ListNode(9);
		a9_1->next = a9_2;
		a9_2->next = a9_3;
		a9_3->next = a9_4;
		return a9_1;
	}


	ListNode* GetTestData3()
	{
		ListNode* a4 = new ListNode(4);
		ListNode* a5 = new ListNode(5);
		ListNode* a6 = new ListNode(6);

		a5->next = a6;
		a6->next = a4;

		return a5;
	}
	ListNode* GetTestData4()
	{
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);
		a2->next = a4;
		a4->next = a3;
		return a2;
	}

};

