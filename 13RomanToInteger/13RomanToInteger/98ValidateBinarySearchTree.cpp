#include <iostream>
#include <vector>
#include <stack>
#include "tree.h"

using namespace std;

//*******************************Description**********************************************
//Given a binary tree, determine if it is a valid binary search tree (BST).
//
//Assume a BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//***************************************************************************************

class Solution {
private:
	TreeNode* cur;
	vector<int> vec;
	stack<TreeNode*> sta;
	TreeNode* pre;
public:
	bool isValidBST(TreeNode* root) {
		cur = root;
		while (cur != NULL || !sta.empty())
		{
			while (cur != NULL)
			{
				sta.push(cur);
				cur = cur->left;
			}
			cur = sta.top();
			sta.pop();
			//注意这里有一个是>=，因为在等于的时候也不是BST
			if (pre != NULL && pre->val >= cur->val)
			{
				return false;
			}
			pre = cur;
			cur = cur->right;
		}
		return true;
	}
};

class TestClass{
public:
	static TreeNode* GetTestData()
	{
		TreeNode* root0 = new TreeNode(0);
		TreeNode* root2 = new TreeNode(2);
		TreeNode* root3 = new TreeNode(3);
		TreeNode* root4 = new TreeNode(4);
		TreeNode* root5 = new TreeNode(5);
		TreeNode* root6 = new TreeNode(6);
		TreeNode* root7 = new TreeNode(7);
		TreeNode* root8 = new TreeNode(8);
		TreeNode* root9 = new TreeNode(9);

		root4->left = root3;
		root4->right = root5;

		root2->left = root0;
		root2->right = root4;

		root8->left = root7;
		root8->right = root9;

		root6->left = root2;
		root6->right = root8;

		return root6;
	}
};