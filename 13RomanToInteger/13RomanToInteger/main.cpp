#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>

#include "144BinaryTreePreoderTraveral.cpp"

using namespace std;




int main()
{
	queue<int> que;
	
	for (size_t i = 0; i < 10; i++)
	{
		que.push(i);
	}
	
	while (!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}


	//TreeNode root = TreeNode(1);
	//TreeNode right = TreeNode(2);
	//TreeNode left = TreeNode(3);
	//right.left = &left;
	//root.right = &right;
	//Solution mySolution = Solution();
	//vector<int> test = mySolution.preorderTraversal(&root);
	//for (size_t i = 0; i < test.size(); i++)
	//{
	//	cout << test[i] << endl;
	//}

	getchar();
	getchar();
	return 0;
}