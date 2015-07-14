#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>

#include "145BinaryTreePostorderTraversal.cpp"

using namespace std;

int main()
{
	TestClass myTestClass = TestClass();


	Solution mySolution = Solution();
	TreeNode* test = myTestClass.GetTestData();
	vector<int> re = mySolution.postorderTraversal(test);
	
	getchar();
	getchar();
	return 0;
}