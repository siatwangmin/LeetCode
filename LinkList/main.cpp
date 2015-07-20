#include <iostream>
#include <time.h>
#include "tree.h"
#include "linklist.h"


#include "109ConvertSortedListtoBinarySearchTree.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();

	Solution mySolution = Solution();
	Solution mySolution1 = Solution();
	Solution mySolution2 = Solution();
	Solution mySolution3 = Solution();
	TestClass myTest = TestClass();
	
	
	TreeNode* re0 = mySolution.sortedListToBST(NULL);
	TreeNode* re1 = mySolution1.sortedListToBST(myTest.GetTestData1());
	TreeNode* re2 = mySolution2.sortedListToBST(myTest.GetTestData2());
	TreeNode* re3 = mySolution3.sortedListToBST(myTest.GetTestData3());

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}