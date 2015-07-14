#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>

#include "222CountCompleteTreeNodes.cpp"

using namespace std;

int main()
{
	TestClass myTestClass = TestClass();
	TreeNode* root = myTestClass.GetTestData();
	Solution mySolution = Solution();
	cout<< mySolution.countNodes(root);
	getchar();
	getchar();
	return 0;
}