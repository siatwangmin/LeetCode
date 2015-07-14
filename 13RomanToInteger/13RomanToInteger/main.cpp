#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>

#include "114FlattenBinaryTreetoLinkedList.cpp"

using namespace std;

int main()
{
	TestClass myTestClass = TestClass();
	TreeNode* root = myTestClass.GetTestData();
	Solution mySolution = Solution();
	mySolution.flatten(root);
	getchar();
	getchar();
	return 0;
}