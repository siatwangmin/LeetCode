#include <iostream>
#include "tree.h"

using namespace std;


//**********************************Description********************************************************
//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root-to-leaf numbers.
//
//For example,
//
//    1
//   / \
//  2   3
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//
//Return the sum = 12 + 13 = 25.
//******************************************************************************************************

class Solution {
private:
	int RecursiveSum(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int result = 0;
		if (root->left != NULL)
		{
			result += root->val *10 + RecursiveSum(root->left);
		}
		if (root->right != NULL)
		{
			result += root -> val* 10 + RecursiveSum(root->right);
		}
		if (root->left == NULL && root->right == NULL)
		{
			result += root->val;
		}
		return result;
	}
public:
	int sumNumbers(TreeNode* root) {
		return RecursiveSum(root);
	}
};