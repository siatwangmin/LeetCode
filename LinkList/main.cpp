#include <iostream>
#include <time.h>
#include "tree.h"
#include "linklist.h"


#include "92ReverseLinkedListII.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();

	Solution mySolution = Solution();
	Solution mySolution1 = Solution();
	Solution mySolution2 = Solution();
	Solution mySolution3 = Solution();
	TestClass myTest = TestClass();
	
	
	ListNode* re0 = mySolution.reverseBetween(NULL,2,4);
	ListNode* re1 = mySolution1.reverseBetween(myTest.GetTestData1(), 2, 4);
	ListNode* re2 = mySolution1.reverseBetween(myTest.GetTestData1(), 1, 5);
	ListNode* re3 = mySolution1.reverseBetween(myTest.GetTestData2(), 1, 1);
	
	//*ListNode* re2 = mySolution2.insertionSortList(myTest.GetTestData2());
	//ListNode* re3 = mySolution3.insertionSortList(myTest.GetTestData3());* /

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}