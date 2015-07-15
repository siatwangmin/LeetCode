#include <iostream>
#include <queue>

using namespace std;


//Implement the following operations of a stack using queues.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//empty() -- Return whether the stack is empty.
//Notes:
//You must use only standard operations of a queue -- which means only push to back, peek/pop 
//from front, size, and is empty operations are valid.
//Depending on your language, queue may not be supported natively. You may simulate a queue by
//using a list or deque (double-ended queue), as long as you use only standard operations of a
//queue.
//You may assume that all operations are valid (for example, no pop or top operations will be 
//called on an empty stack).


class Stack {
private:
	queue<int> que1;
	queue<int> que2;
	int size = 0 ;
public:
	// Push element x onto stack.
	void push(int x) {
		que1.push(x);
		size++;
	}

	// Removes the element on top of the stack.
	void pop() {
		for (int i = 0; i < size - 1; i++)
		{
			que2.push(que1.front());
			que1.pop();
		}
		que1.pop();
		while (!que2.empty())
		{
			que1.push(que2.front());
			que2.pop();
		}
		size--;
	}

	// Get the top element.
	int top() {
		for (int i = 0; i < size - 1; i++)
		{
			que2.push(que1.front());
			que1.pop();
		}
		int result = que1.front();
		que2.push(que1.front());
		que1.pop();
		while (!que2.empty())
		{
			que1.push(que2.front());
			que2.pop();
		}
		return result;
	}

	// Return whether the stack is empty.
	bool empty() {
		if (que1.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};