#include <iostream>
#include <time.h>
#include "tree.h"
#include "linklist.h"


#include "147InsertionSortList.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();

	Solution mySolution = Solution();
	Solution mySolution1 = Solution();
	Solution mySolution2 = Solution();
	Solution mySolution3 = Solution();
	TestClass myTest = TestClass();
	
	
	ListNode* re0 = mySolution.insertionSortList(NULL);
	ListNode* re1 = mySolution1.insertionSortList(myTest.GetTestData1());
	ListNode* re2 = mySolution2.insertionSortList(myTest.GetTestData2());
	ListNode* re3 = mySolution3.insertionSortList(myTest.GetTestData3());

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}