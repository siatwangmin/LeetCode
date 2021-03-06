#include <iostream>
#include <vector>
#include "link.h"

using namespace std;


//********************************Description******************************************************
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.
//*************************************************************************************************


//class MinStack {
//	vector<DoubleListNode*> sta;
//	DoubleListNode* minNode;
//	DoubleListNode* cur;
//	DoubleListNode* pre;
//public:
//	MinStack()
//	{
//		minNode = new DoubleListNode(0);
//	}
//	void push(int x) {
//		DoubleListNode* myNode = new DoubleListNode(x);
//		
//		if (minNode->next == NULL)
//		{
//			minNode->next = myNode;
//			myNode->pre = minNode;
//		}
//		else
//		{
//			cur = minNode->next;
//			pre = minNode;
//			while (cur != NULL && myNode->val > cur->val)
//			{
//				pre = cur;
//				cur = cur->next;
//			}
//			myNode->pre = pre;
//			if (pre != NULL)
//				pre->next = myNode;
//			myNode->next = cur;
//			if (cur != NULL)
//				cur->pre = myNode;
//
//		}
//		sta.push_back(myNode);
//	}
//
//	void pop() {
//		DoubleListNode* stackTop = sta[sta.size() - 1];
//		if (stackTop == minNode->next)
//		{
//			minNode->next = stackTop->next;
//		}
//		if (stackTop->pre != NULL)
//			stackTop->pre->next = stackTop->next;
//		if (stackTop->next != NULL)
//			stackTop->next->pre = stackTop->pre;
//		delete stackTop;
//		sta.pop_back();
//	}
//
//	int top() {
//		return sta[sta.size() - 1]->val;
//	}
//
//	int getMin() {
//		return minNode->next->val;
//	}
//};


class MinStack {
	vector<int> sta;
	vector<int> minSta;
public:
	void push(int x) {
		sta.push_back(x);
		if (minSta.empty())
		{
			minSta.push_back(x);
		}
		else if (x <= minSta[minSta.size() - 1])
		{
			minSta.push_back(x);
		}
	}

	void pop() {
		if (sta.empty())
		{
			return;
		}
		else
		{
			if (sta[sta.size() - 1] == minSta[minSta.size() - 1])
				minSta.pop_back();
			sta.pop_back();
		}
	}

	int top() {
		if (!sta.empty())
		{
			return sta[sta.size() - 1];
		}
		return 0;
	}

	int getMin() {
		if (!minSta.empty())
			return minSta[minSta.size() - 1];
		return 0;
	}
};