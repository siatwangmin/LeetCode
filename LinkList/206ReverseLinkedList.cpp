#include <iostream>
#include <vector>
#include "linklist.h"

using namespace std;

//********  Description *******
//Reverse a singly linked list.
//******************************

//方法一：自己的第一想法 8ms
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		vector<ListNode*> vec;
//		ListNode* cur = head;
//		while (cur != NULL)
//		{
//			vec.push_back(cur);
//			cur = cur->next;
//		}
//
//		for (int i = vec.size() - 2; i  > -1; i--)
//		{
//			vec[i + 1]->next = vec[i];
//		}
//
//		if (vec.size() != 0)
//		{
//			vec[0]->next = NULL;
//			return vec[vec.size() - 1];
//		}
//		else
//		{
//			return NULL;
//		}
//	}
//};

//方法二：
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* cur = head;
		ListNode* temp = NULL;
		while (cur != NULL)
		{
			temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
};


class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* a = new ListNode(1);
		return a;
	}

	ListNode* GetTestData2()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);

		a1->next = a2;

		return a1;
	}

	ListNode* GetTestData3()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		a1->next = a2;
		a2->next = a3;

		return a1;
	}
};