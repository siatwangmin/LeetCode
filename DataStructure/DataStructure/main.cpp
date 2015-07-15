#include <iostream>
#include <queue>
#include <vector>
#include "tree.h"

#include "225ImplementStackusingQueues.cpp"


using namespace std;

int main()
{
	Stack myStack = Stack();
	for (size_t i = 0; i < 10; i++)
	{
		myStack.push(i);
	}
	while (!myStack.empty())
	{
		cout << myStack.top() << endl;
		myStack.pop();
	}
	getchar();
	getchar();
	return 0 ;
}