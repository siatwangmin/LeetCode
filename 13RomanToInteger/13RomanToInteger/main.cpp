#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>

#include "98ValidateBinarySearchTree.cpp"

using namespace std;

int main()
{
	TestClass myTestClass = TestClass();
	TreeNode* root = myTestClass.GetTestData();
	Solution mySolution = Solution();
	bool re = mySolution.isValidBST(root);
	getchar();
	getchar();
	return 0;
}