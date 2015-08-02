#include <iostream>
#include <time.h>
#include "tree.h"
#include "linklist.h"


#include "61RotateList.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();

	Solution mySolution = Solution();
	Solution mySolution1 = Solution();
	Solution mySolution2 = Solution();
	Solution mySolution3 = Solution();
	TestClass myTest = TestClass();
	
	ListNode* re2 = mySolution.rotateRight(NULL, 1);

	ListNode* re3 = mySolution.rotateRight(myTest.GetTestData1(),2);
	ListNode* re4 = mySolution.rotateRight(myTest.GetTestData1(), 1);
	ListNode* re5 = mySolution.rotateRight(myTest.GetTestData1(), 10);

	
	//*ListNode* re2 = mySolution2.insertionSortList(myTest.GetTestData2());
	//ListNode* re3 = mySolution3.insertionSortList(myTest.GetTestData3());* /

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}