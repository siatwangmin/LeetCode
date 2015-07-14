#include <iostream>
#include <vector>
#include <stack>
#include "tree.h"

using namespace std;


//*********************************************************Description*************************************************
//Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
//**********************************************************************************************************************

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class BSTIterator {
private:
	stack<TreeNode*> sta;
	TreeNode* cur;
public:
	BSTIterator(TreeNode *root) {
		if (root == NULL)
			return;
			cur = root;
			while (cur != NULL)
			{
				sta.push(cur);
				cur = cur->left;
			}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (!sta.empty())
			return true;
		else
			return false;
	}

	/** @return the next smallest number */
	int next() {
		int result = 0;
		cur = sta.top();
		sta.pop();
		result = cur->val;
		cur = cur->right;
		while (cur != NULL)
		{
			sta.push(cur);
			cur = cur->left;
		}
		return result;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/


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