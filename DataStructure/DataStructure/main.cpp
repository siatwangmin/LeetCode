#include <iostream>
#include <queue>
#include <vector>
#include "tree.h"
#include <string>
#include "link.h"

#include "42TrappingRainWater.cpp"


using namespace std;

int main()
{
	vector<int> test;
	test.push_back(0);
	test.push_back(1);
	test.push_back(0);
	test.push_back(2);
	test.push_back(1);
	test.push_back(0);
	test.push_back(1);
	test.push_back(3);
	test.push_back(2);
	test.push_back(1);
	test.push_back(2);
	test.push_back(1);

	vector<int> test2;
	test2.push_back(4);
	test2.push_back(2);
	test2.push_back(3);
	Solution mySolution = Solution();
	int re = mySolution.trap(test);
	int re2 = mySolution.trap(test2);

	getchar();
	getchar();
	return 0;
}