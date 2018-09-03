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
	bool _result = true;
	void recursiveIsSame(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL)
		{
			return;
		}
		if (p == NULL && q != NULL)
		{
			_result = false;
			return;
		}
		if (p != NULL && q == NULL)
		{
			_result = false;
			return;
		}

		if (p->val != q->val)
			_result = false;

		recursiveIsSame(p->left, q->left);
		recursiveIsSame(p->right, q->right);
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		recursiveIsSame(p, q);
		return _result;
	}

	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return NULL;
		}
		TreeNode* invertRoot = new TreeNode(root->val);
		
		invertRoot->right = invertTree(root->left);
		invertRoot->left = invertTree(root->right);

		return invertRoot;
	}

public:
	bool isSymmetric(TreeNode* root) {
		TreeNode* inverted = invertTree(root);
		return isSameTree(inverted, root);

	}
};