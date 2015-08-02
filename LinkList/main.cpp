#include <iostream>
#include <time.h>
#include "tree.h"
#include "linklist.h"


#include "82RemoveDuplicatesfromSortedListII.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();

	Solution mySolution = Solution();
	Solution mySolution1 = Solution();
	Solution mySolution2 = Solution();
	Solution mySolution3 = Solution();
	TestClass myTest = TestClass();
	

	ListNode* re3 = mySolution.deleteDuplicates(myTest.GetTestData1());
	ListNode* re4 = mySolution.deleteDuplicates(myTest.GetTestData2());
	
	//*ListNode* re2 = mySolution2.insertionSortList(myTest.GetTestData2());
	//ListNode* re3 = mySolution3.insertionSortList(myTest.GetTestData3());* /

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}