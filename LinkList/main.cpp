#include <iostream>
#include <time.h>
#include "tree.h"
#include "linklist.h"


#include "23MergekSortedLists.cpp"

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

	ListNode* re2 = mySolution.mergeKLists(vec);

	ListNode* re3 = mySolution.mergeKLists(myTest.GetTestData1());

	
	//*ListNode* re2 = mySolution2.insertionSortList(myTest.GetTestData2());
	//ListNode* re3 = mySolution3.insertionSortList(myTest.GetTestData3());* /

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}