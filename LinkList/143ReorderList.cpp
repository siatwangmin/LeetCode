#include <iostream>
#include <vector>
#include "linklist.h"

using namespace std;

//---------------------------------------------------------------------------------
//
//Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
//reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­
//
//You must do this in-place without altering the nodes' values.
//
//For example,
//Given {1,2,3,4}, reorder it to {1,4,2,3}.
//
//---------------------------------------------------------------------------------

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL)
			return;
		ListNode* cur = head;
		vector<ListNode*> vec;
		vector<ListNode*> res;
		while (cur)
		{
			vec.push_back(cur);
			cur = cur->next;
		}
		for (size_t i = 0; i < vec.size(); i++)
		{
			if (i <= (vec.size() - 1 - i))
			{
				res.push_back(vec[i]);
				res.push_back(vec[vec.size()-1 -i]);
			}
			else
			{
				break;
			}
		}
		for (size_t i = 1; i < res.size(); i++)
		{
			res[i - 1]->next = res[i];
		}
		res[res.size() - 1]->next = NULL;
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

		a1->next = a2;
		a2->next = a3;
		a3->next = a4;
		return a1;
	}
	ListNode* GetTestData2()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);
		ListNode* a5 = new ListNode(5);

		a1->next = a2;
		a2->next = a3;
		a3->next = a4;
		a4->next = a5;
		return a1;
	}
};