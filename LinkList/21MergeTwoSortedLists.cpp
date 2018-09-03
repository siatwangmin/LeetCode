#include <iostream>
#include <vector>
#include "linklist.h"

using namespace std;

//************************   Description   *****************************************
//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.
//**********************************************************************************


//方法一：不优雅
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* curL1 = l1;
		ListNode* curL2 = l2;
		ListNode* res = NULL;
		ListNode* curRes = NULL;

		while (curL1 != NULL || curL2 != NULL)
		{
			if (curL1 == NULL)
			{
				if (res == NULL)
				{
					res = curL2;
				}
				else
				{
					curRes->next = curL2;
				}
				break;
			}
			else if (curL2 == NULL)
			{
				if (res == NULL)
				{
					res = curL1;
				}
				else
				{
					curRes->next = curL1;
				}
				break;
			}
			else
			{
				if (res == NULL)
				{
					if (curL1->val < curL2->val)
					{
						res = curL1;
						curL1 = curL1->next;
					}
					else
					{
						res = curL2;

						curL2 = curL2->next;
					}
					curRes = res;
				}
				else
				{
					if (curL1->val < curL2->val)
					{
						curRes->next = curL1;
						curRes = curRes->next;
						curL1 = curL1->next;
					}
					else
					{
						curRes->next = curL2;
						curRes = curRes->next;
						curL2 = curL2->next;
					}
				}
			}
			
		}
		return res;
	}
};

//方法二
//class Solution {
//private:
//	vector<ListNode*> vec;
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		ListNode* curL1 = l1;
//		ListNode* curL2 = l2;
//		while (curL1 != NULL && curL2 != NULL)
//		{
//			if (curL1->val < curL2->val)
//			{
//				vec.push_back(curL1);
//				curL1 = curL1->next;
//			}
//			else
//			{
//				vec.push_back(curL2);
//				curL2 = curL2->next;
//			}
//		}
//		while (curL1 != NULL)
//		{
//			vec.push_back(curL1);
//			curL1 = curL1->next;
//		}
//		while (curL2 != NULL)
//		{
//			vec.push_back(curL2);
//			curL2 = curL2->next;
//		}
//
//		for (size_t i = 1; i < vec.size(); i++)
//		{
//			vec[i - 1]->next = vec[i];
//
//		}
//		
//		if (vec.size() == 0)
//			return NULL;
//		else
//		{
//			return vec[0];
//		}
//
//	}
//};


class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* node1 = new ListNode(1);
		ListNode* node2 = new ListNode(2);
		ListNode* node6 = new ListNode(6);
		ListNode* node9 = new ListNode(9);

		node1->next = node2;
		node2->next = node6;
		node6->next = node9;

		return node1;

	}

	ListNode* GetTestData2()
	{
		ListNode* node1 = new ListNode(1);
		ListNode* node2 = new ListNode(2);
		ListNode* node5 = new ListNode(5);
		ListNode* node8 = new ListNode(8);

		node1->next = node2;
		node2->next = node5;
		node5->next = node8;

		return node1;

	}

};