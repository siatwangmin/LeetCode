#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>

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
	vector<vector<int>> test = mySolution.levelOrder(&root);
	
	cout << test.size() << endl;

	getchar();
	getchar();
	return 0;
}