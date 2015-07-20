#include <iostream>
#include <time.h>
#include "tree.h"
#include "linklist.h"


#include "86PartitionList.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();

	Solution mySolution = Solution();
	Solution mySolution1 = Solution();
	Solution mySolution2 = Solution();
	Solution mySolution3 = Solution();
	TestClass myTest = TestClass();
	
	
	ListNode* re0 = mySolution.partition(NULL,0);
	ListNode* re1 = mySolution1.partition(myTest.GetTestData1(),1);
	ListNode* re2 = mySolution2.partition(myTest.GetTestData1(),3);
	ListNode* re3 = mySolution3.partition(myTest.GetTestData1(),5);

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}