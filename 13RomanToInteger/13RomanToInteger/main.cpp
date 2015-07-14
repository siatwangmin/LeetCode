#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>

#include "173BinarySearchTreeIterator.cpp"

using namespace std;

int main()
{
	TestClass myTestClass = TestClass();


	
	TreeNode* test = myTestClass.GetTestData();
	
	BSTIterator i = BSTIterator(test);
	while (i.hasNext()) cout << i.next();
	
	getchar();
	getchar();
	return 0;
}