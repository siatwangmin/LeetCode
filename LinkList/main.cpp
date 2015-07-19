#include <iostream>
#include <time.h>
#include "linklist.h"


#include "160IntersectionofTwoLinkedLists.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();
	int i = 500;

	Solution mySolution = Solution();
	TestClass myTest = TestClass();
	
	ListNode* A = myTest.GetTestData1();
	ListNode* B = myTest.GetTestData2();
	ListNode* re1 = mySolution.getIntersectionNode(A,B);

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}