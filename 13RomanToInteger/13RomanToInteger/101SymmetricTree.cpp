#include <iostream>
#include <vector>
#include "Tree.h"

using namespace std;


//************************************************************************************
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

//For example, this binary tree is symmetric:
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//But the following is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3
//Note:
//Bonus points if you could solve it both recursively and iteratively.
//***********************************************************************************


//方法一：现将原树镜像一下
class Solution {
private:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return NULL;
		}
		invertTree(root->left);
		invertTree(root->right);

		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		return root;
	}

public:
	bool isSymmetric(TreeNode* root) {

	}
};