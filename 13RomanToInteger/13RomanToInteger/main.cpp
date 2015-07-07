#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>

#include "144BinaryTreePreoderTraveral.cpp"

using namespace std;




int main()
{
	queue<int> que;
	vector<int> row;
	vector<vector<int>> result;
	for (size_t i = 0; i < 10; i++)
	{
		que.push(i);
		row.push_back(i);
		result.push_back(row);
		row.clear();
	}

	while (!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}

	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t j = 0; j < 1; j++)
		{
			cout << result[i][j] << endl;
		}

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