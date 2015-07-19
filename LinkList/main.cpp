#include <iostream>
#include <time.h>
#include "linklist.h"


#include "234PalindromeLinkedList.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();
	int i = 500;

	Solution mySolution = Solution();
	TestClass myTest = TestClass();
	
	bool re1 = mySolution.isPalindrome(myTest.GetTestData1());
	bool re2 = mySolution.isPalindrome(myTest.GetTestData2());


	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}