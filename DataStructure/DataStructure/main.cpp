#include <iostream>
#include <queue>
#include <vector>
#include "tree.h"

#include "155MinStack.cpp"


using namespace std;

int main()
{
	MinStack mySta = MinStack();

	mySta.push(6);
	mySta.push(6);
	mySta.push(7);

	cout << mySta.top() << endl;

	mySta.pop();

	cout << mySta.getMin() << endl;

	mySta.pop();

	cout << mySta.getMin() << endl;

	mySta.pop();

	mySta.push(7);

	cout << mySta.top() << endl;

	cout << mySta.getMin() << endl;

	mySta.push(8);

	cout << mySta.top() << endl;

	cout << mySta.getMin() << endl;

	mySta.pop();

	cout << mySta.getMin() << endl;

	getchar();
	getchar();
	return 0 ;
}