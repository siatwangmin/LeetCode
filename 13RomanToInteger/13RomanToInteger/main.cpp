#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>

#include "104BinaryTreeLevelOrderTraversal.cpp"

using namespace std;




int main()
{
	
	TreeNode root = TreeNode(1);
	TreeNode right = TreeNode(2);
	TreeNode left = TreeNode(3);
	right.left = &left;
	root.right = &right;
	Solution mySolution = Solution();
	//vector<vector<int>> test = mySolution.levelOrder(&root);
	
	//cout << test.size() << endl;

	vector<int> testVector;
	stack<int> testStack;

	for (size_t i = 0; i < 10; i++)
	{
		testVector.insert(testVector.begin(), i);
	}

	for (size_t i = 0; i < testVector.size(); i++)
	{
		cout << testVector[i] << '\t';
	}

	getchar();
	getchar();
	return 0;
}