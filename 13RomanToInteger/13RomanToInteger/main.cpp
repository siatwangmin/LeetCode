#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>

#include "99RecoverBinarySearchTree.cpp"

using namespace std;

int main()
{
	TestClass myTestClass = TestClass();
	TreeNode* root = myTestClass.GetTestData();
	Solution mySolution = Solution();
	mySolution.recoverTree(root);
	getchar();
	getchar();
	return 0;
}