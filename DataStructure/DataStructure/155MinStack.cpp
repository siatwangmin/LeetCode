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


class MinStack {
	vector<DoubleListNode*> sta;
	DoubleListNode* minNode;
	DoubleListNode* cur;
	DoubleListNode* pre;
public:
	void push(int x) {
		DoubleListNode* myNode = new DoubleListNode(x);
		
		if (minNode == NULL)
			minNode = myNode;
		else
		{
			cur = minNode;
			while (cur != NULL && myNode->val > cur->val)
			{
				pre = cur;
				cur = cur->next;
			}
			myNode->pre = pre;
			if (pre != NULL)
				pre->next = myNode;
			myNode->next = cur;
			if (cur != NULL)
				cur->pre = myNode;
		}
		sta.push_back(myNode);
	}

	void pop() {
		DoubleListNode* stackTop = sta[sta.size() - 1];
		if (stackTop->pre != NULL)
			stackTop->pre->next = stackTop->next;
		if (stackTop->next != NULL)
			stackTop->next->pre = stackTop->pre;
		delete stackTop;
		sta.pop_back();
	}

	int top() {
		return sta[sta.size() - 1]->val;
	}

	int getMin() {
	}
};