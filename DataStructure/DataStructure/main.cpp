#include <iostream>
#include <queue>
#include <vector>
#include "tree.h"

#include "232ImplementQueueusingStacks.cpp"


using namespace std;

int main()
{
	Queue myQue = Queue();
	for (size_t i = 0; i < 10; i++)
	{
		myQue.push(i);
	}

	//queue<int> testQue;
	//testQue.push(1);
	//cout << testQue.front() << endl;
	//testQue.pop();
	//testQue.pop();
	//cout << testQue.front() << endl;

	//myQue.pop();

	//while (!myQue.empty())
	//{
	//	cout << myQue.peek() << endl;
	//	myQue.pop();
	//}
	for (size_t j = 0; j < 20; j++)
	{
		cout << j << ":" << myQue.peek() << endl;
		myQue.pop();
	}
	
	getchar();
	getchar();
	return 0 ;
}