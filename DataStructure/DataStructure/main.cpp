#include <iostream>
#include <queue>
#include <vector>
#include "tree.h"

#include "155MinStack.cpp"


using namespace std;

int main()
{
	MinStack mySta = MinStack();

	for (size_t i = 5; i > 0; i--)
	{
		mySta.push(i);
		cout << mySta.getMin();
	}
	cout << endl;
	mySta.pop();
	mySta.pop();
	mySta.pop();
	mySta.pop();
	mySta.pop();
	cout << mySta.getMin();

	getchar();
	getchar();
	return 0 ;
}