#include <iostream>
#include <vector>
#include "tree.h"


using namespace std;


//******************************************************************************************************
//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
//For example:
//Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//return
//[
//   [5,4,11,2],
//   [5,8,4,5]
//]
//******************************************************************************************************

class Solution {
private:
	vector<vector<int>> result;
	vector<int> que;

	void recursiveFind(TreeNode* root, int sum)
	{
		if (root == NULL)
			return;
		que.push_back(root->val);
		sum = sum - root->val;
		if (sum == 0)
		{
			if (root->left == NULL && root->right == NULL)
			{
				result.push_back(que);
			}
		}
		recursiveFind(root->left, sum);
		recursiveFind(root->right, sum);
		que.pop_back();
	}

public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		recursiveFind(root, sum);
		return result;
	}
};