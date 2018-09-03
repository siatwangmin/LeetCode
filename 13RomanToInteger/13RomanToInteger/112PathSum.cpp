#include <iostream>
#include "tree.h"

using namespace std;

//**************************************************************************************************************************************************
//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//
//For example:
//Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1
//return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
//*********************************************************************************************************************************************************

class Solution {
private:
	bool result = false;
	
	void recursiveFind(TreeNode* root, int sum)
	{
		if (root == NULL)
			return;

		sum = sum - root->val;
		if (sum == 0)
		{
			if (root->left == NULL && root->right == NULL)
			{
				result = true;
			}
		}

		recursiveFind(root->left, sum);
		recursiveFind(root->right, sum);
	}

public:
	bool hasPathSum(TreeNode* root, int sum) {
		recursiveFind(root, sum);
		return result;
	}
};