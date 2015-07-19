#include <iostream>
#include <time.h>
#include "linklist.h"


#include "141LinkedListCycle.cpp"

using namespace std;

int main()
{
	clock_t startTime = clock();
	int i = 500;

	Solution mySolution = Solution();
	TestClass myTest = TestClass();
	
	
	bool re0 = mySolution.hasCycle(NULL);
	bool re1 = mySolution.hasCycle(myTest.GetTestData1());
	bool re2 = mySolution.hasCycle(myTest.GetTestData2());
	bool re3 = mySolution.hasCycle(myTest.GetTestData3());

	clock_t endTime = clock();

	cout << "Time :" << (endTime - startTime) / CLOCKS_PER_SEC << endl;
	getchar();
	getchar();
	return 0;
}