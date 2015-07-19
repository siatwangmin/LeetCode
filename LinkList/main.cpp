#include <iostream>
#include <time.h>
#include "linklist.h"


#include "19RemoveNthNodeFromEndofList.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();
	int i = 500;

	Solution mySolution = Solution();
	TestClass myTest = TestClass();
	
	ListNode* re = mySolution.removeNthFromEnd(myTest.GetTestData(),1);


	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}