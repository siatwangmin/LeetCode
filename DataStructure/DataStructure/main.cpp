#include <iostream>
#include <queue>
#include <vector>
#include "tree.h"
#include <string>
#include "link.h"

#include "227BasicCalculatorII.cpp"


using namespace std;

int main()
{
	//vector<string> test;
	//test.push_back(0);
	//test.push_back(0);
	//test.push_back(1);
	//test.push_back(2);
	//test.push_back(2);
	//test.push_back(3);
	//test.push_back(3);
	//test.push_back(4);
	//test.push_back(4);
	//test.push_back(5);
	//test.push_back(5);

	TestClass testClass = TestClass();

	Solution mySolution = Solution();
	int re = mySolution.calculate(testClass.GetTestData());
	cout << re << endl;
	getchar();
	getchar();
	return 0;
}