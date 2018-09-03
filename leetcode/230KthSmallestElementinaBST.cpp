#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

//**********************************Description**************************************************
//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note: 
//You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.
//
//Follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest
//frequently? How would you optimize the kthSmallest routine?
//
//Hint:
//
//Try to utilize the property of a BST.Show More Hint 
//*****************************************************************************************************

class Solution {
private:
	vector<int> result;
	void inorderTraversal(TreeNode* root) {
		if (root == NULL)
			return;
		inorderTraversal(root->left);
		result.push_back(root->val);
		inorderTraversal(root->right);
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		inorderTraversal(root);
		return result[k - 1];
	}
};
