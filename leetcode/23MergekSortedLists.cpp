#include <iostream>
#include <vector>
#include "linklist.h"

using namespace std;

//--------------------------------------------------------------------------------------------------
//
//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
//-------------------------------------------------------------------------------------------------

//方法一：最直观的方法：Time Out;
class Solution {
private:
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
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
		{
			return NULL;
		}
		if (lists.size() == 1)
		{
			return lists[0];
		}
		if (lists.size() == 2)
		{
			return mergeTwoLists(lists[0], lists[1]);
		}
		vector<ListNode*> lo;
		vector<ListNode*> hi;
		int i = 0;
		for (; i < lists.size()/2; i++)
		{
			lo.push_back(lists[i]);
		}
		for (; i < lists.size();i++)
		{
			hi.push_back(lists[i]);
		}
		return mergeTwoLists(mergeKLists(lo), mergeKLists(hi));
	}
};

//方法二:仍旧是TimeOut
//class Solution {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		vector<ListNode*> vecCur;
//		ListNode* res = new ListNode(0);
//		ListNode* e = res;
//
//		ListNode* min = NULL;
//		int indx = -1;
//		for (int i = 0; i < lists.size(); i++)
//		{
//			vecCur.push_back(lists[i]);
//		}
//
//		while (!vecCur.empty())
//		{
//			for (int i = 0; i < vecCur.size(); i++)
//			{
//				if (vecCur[i] != NULL)
//				{
//					if (min == NULL)
//					{
//						min = vecCur[i];
//						indx = i;
//					}
//					if (vecCur[i]->val < min->val)
//					{
//						min = vecCur[i];
//						indx = i;
//					}
//				}
//				else
//				{
//					vecCur.erase(vecCur.begin() + i);
//				}
//			}
//			if (min != NULL)
//			{
//
//				e->next = min;
//				e = e->next;
//				vecCur[indx] = vecCur[indx]->next;
//				if (vecCur[indx] == NULL)
//				{
//					vecCur.erase(vecCur.begin() + indx);
//				}
//				min = NULL;
//				indx = -1;
//
//			}
//		}
//
//		return res->next;
//
//	}
//};


//class Solution {
//private:
//	vector<ListNode*> vec;
//
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		vec = lists;
//		int lo = 0;
//		int hi = lists.size();
//		
//		
//	}
//};

class TestClass{
public:
	vector<ListNode*> GetTestData1()
	{
		vector<ListNode*> vec;
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);

		ListNode* a4 = new ListNode(4);
		ListNode* a5 = new ListNode(5);
		ListNode* a6 = new ListNode(6);

		ListNode* a7 = new ListNode(7);
		ListNode* a8 = new ListNode(8);
		ListNode* a9 = new ListNode(9);

		a1->next = a4;
		a4->next = a7;

		a2->next = a5;
		a5->next = a8;

		a3->next = a6;
		a6->next = a9;

		vec.push_back(a1);
		vec.push_back(a2);
		vec.push_back(a3);

		return vec;
	}
};