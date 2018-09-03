#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//*************************Description*******************************************************
//Implement the following operations of a queue using stacks.
//
//push(x) -- Push element x to the back of queue.
//pop() -- Removes the element from in front of queue.
//peek() -- Get the front element.
//empty() -- Return whether the queue is empty.
//Notes:
//You must use only standard operations of a stack -- which means only push to top, peek/pop
//from top, size, and is empty operations are valid.
//Depending on your language, stack may not be supported natively. You may simulate a stack 
//by using a list or deque (double-ended queue), as long as you use only standard operations
//of a stack.
//You may assume that all operations are valid (for example, no pop or peek operations will 
//be called on an empty queue).
//******************************************************************************************

class Queue {
private:
	stack<int> stack1;
	stack<int> stack2;
public:
	// Push element x to the back of queue.
	void push(int x) {
		stack1.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		if (!stack2.empty())
		{
			stack2.pop();
		}
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
	}

	// Get the front element.
	int peek(void) {

		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int result = stack2.top();
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return result;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		if (stack1.empty())
			return true;
		else
			return false;
	}
};