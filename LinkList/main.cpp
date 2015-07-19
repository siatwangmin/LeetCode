#include <iostream>
#include <time.h>
#include "linklist.h"


#include "206ReverseLinkedList.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();
	int i = 500;

	Solution mySolution = Solution();
	TestClass myTest = TestClass();
	
	ListNode* A = myTest.GetTestData1();
	ListNode* B = myTest.GetTestData2();
	ListNode* re0 = mySolution.reverseList(NULL);
	ListNode* re1 = mySolution.reverseList(A);
	ListNode* re2 = mySolution.reverseList(B);
	ListNode* re3 = mySolution.reverseList(myTest.GetTestData3());

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}