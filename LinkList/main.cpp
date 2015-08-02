#include <iostream>
#include <time.h>
#include "tree.h"
#include "linklist.h"


#include "25RerverseNodeinkGroup.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();

	Solution mySolution = Solution();
	Solution mySolution1 = Solution();
	Solution mySolution2 = Solution();
	Solution mySolution3 = Solution();
	TestClass myTest = TestClass();
	

	ListNode* re3 = mySolution.reverseKGroup(NULL, 2);
	ListNode* re2 = mySolution.reverseKGroup(myTest.GetTestData1(), 1);
	ListNode* re0 = mySolution.reverseKGroup(myTest.GetTestData1(), 2);
	ListNode* re1 = mySolution.reverseKGroup(myTest.GetTestData1(), 3);
	
	//*ListNode* re2 = mySolution2.insertionSortList(myTest.GetTestData2());
	//ListNode* re3 = mySolution3.insertionSortList(myTest.GetTestData3());* /

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}