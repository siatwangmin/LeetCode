#include <iostream>
#include <time.h>
#include "linklist.h"


#include "83RemoveDuplicatesfromSortedList.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();
	int i = 500;

	Solution mySolution = Solution();
	TestClass myTest = TestClass();
	
	ListNode* re = mySolution.deleteDuplicates(myTest.GetTestData());


	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}