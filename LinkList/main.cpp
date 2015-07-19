#include <iostream>
#include <time.h>
#include "linklist.h"


#include "24SwapNodesinPairs.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();
	int i = 500;

	Solution mySolution = Solution();
	TestClass myTest = TestClass();
	
	
	ListNode* re0 = mySolution.swapPairs(NULL);
	ListNode* re1 = mySolution.swapPairs(myTest.GetTestData1());
	ListNode* re2 = mySolution.swapPairs(myTest.GetTestData2());
	ListNode* re3 = mySolution.swapPairs(myTest.GetTestData3());

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}