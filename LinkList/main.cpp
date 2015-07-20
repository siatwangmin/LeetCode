#include <iostream>
#include <time.h>
#include "linklist.h"


#include "142LinkedListCycleII.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();

	Solution mySolution = Solution();
	TestClass myTest = TestClass();
	
	
	ListNode* re0 = mySolution.detectCycle(NULL);
	ListNode* re1 = mySolution.detectCycle(myTest.GetTestData1());
	ListNode* re2 = mySolution.detectCycle(myTest.GetTestData2());
	ListNode* re3 = mySolution.detectCycle(myTest.GetTestData3());

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}