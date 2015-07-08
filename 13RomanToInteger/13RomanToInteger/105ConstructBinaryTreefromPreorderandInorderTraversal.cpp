#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

class Solution {


public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)
			return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
		vector<int>::iterator inorderM = find(inorder.begin(), inorder.end(), root->val);
		int inorderMPosition = inorderM - inorder.begin();
		vector<int> leftInorder;
		vector<int> rightInorder;
		vector<int> leftpreorder;
		vector<int> rightpreorder;

		for (size_t i = 0; i < inorderMPosition; i++)
		{
			leftInorder.push_back(inorder[i]);
		}
		for (size_t i = inorderMPosition + 1; i < inorder.size(); i++)
		{
			rightInorder.push_back(inorder[i]);
		}
		for (size_t i = 1; i < inorderMPosition + 1; i++)
		{
			leftpreorder.push_back(preorder[i]);
		}
		for (size_t i = inorderMPosition + 1; i < preorder.size(); i++)
		{
			rightpreorder.push_back(preorder[i]);
		}

		root->left = buildTree(leftpreorder, leftInorder);
		root->right = buildTree(rightpreorder, rightInorder);

		return root;
	}
};