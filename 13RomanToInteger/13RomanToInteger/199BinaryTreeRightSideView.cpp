#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;


//*****************************************************************************************
//Given a binary tree, imagine yourself standing on the right side of it, return the values
//of the nodes you can see ordered from top to bottom.
//
//For example:
//Given the following binary tree,
//   1            <---
// /   \
//2     3         <---
// \     \
//  5     4       <---
//You should return [1, 3, 4].
//
//Credits:
//Special thanks to @amrsaqr for adding this problem and creating all test cases.
//*****************************************************************************************

//方法一：就是等于层序遍历之后取每个的最后一项
class Solution {

private:
	vector<vector<int>> result;
	vector<int> rightViewResult;

	void recuriveLevelTraverse(TreeNode* root, int level)
	{
		vector<int> row;
		if (root == NULL)
			return;
		if (level == result.size())
		{
			result.push_back(vector<int>());
		}

		result[level].push_back(root->val);

		recuriveLevelTraverse(root->left, level + 1);
		recuriveLevelTraverse(root->right, level + 1);
	}

	void getRightSideView()
	{
		for (size_t i= 0; i < result.size(); i++)
		{
			rightViewResult.push_back(result[i][result[i].size() - 1]);
		}
	}

public:
	vector<int> rightSideView(TreeNode* root) {
		recuriveLevelTraverse(root, 0);
		getRightSideView();
		return rightViewResult;
	}
};

//方法二：................