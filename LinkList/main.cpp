#include <iostream>
#include <time.h>
#include "tree.h"
#include "linklist.h"


#include "143ReorderList.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();

	Solution mySolution = Solution();
	Solution mySolution1 = Solution();
	Solution mySolution2 = Solution();
	Solution mySolution3 = Solution();
	TestClass myTest = TestClass();
	vector<ListNode*> vec;
	vec.push_back(NULL);
	vec.push_back(NULL);

	
	ListNode* re3 = myTest.GetTestData1();
	ListNode* re4 = myTest.GetTestData2();
	mySolution.reorderList(re3);
	mySolution.reorderList(re4);
	
	//*ListNode* re2 = mySolution2.insertionSortList(myTest.GetTestData2());
	//ListNode* re3 = mySolution3.insertionSortList(myTest.GetTestData3());* /

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}