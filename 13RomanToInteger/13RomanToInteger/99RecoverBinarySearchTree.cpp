#include <iostream>
#include <stack>
#include <vector>
#include "tree.h"

using namespace std;

//*********************Description*********************************************************************
//Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Note:
//A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
//*****************************************************************************************************
//方法一：未完成，没有排序
//class Solution {
//private:
//	stack<TreeNode*> sta;
//	TreeNode* cur;
//	TreeNode* pre;
//	vector<TreeNode*> vec;
//	void IterativeInorder(TreeNode* root)
//	{
//		cur = root;
//		while (cur != NULL || !sta.empty())
//		{
//			while (cur != NULL)
//			{
//				sta.push(cur);
//				cur = cur->left;
//			}
//			cur = sta.top();
//			vec.push_back(cur);
//			sta.pop();
//			cur = cur->right;
//		}
//	}
//	
//	void FindMistake()
//	{
//		//排序找到标号不一样的两个数即可
//	}
//
//	void Swap()
//	{
//		if (vec.size() != 2)
//		{
//			return;
//		}
//
//		int temp = vec[0]->val;
//		vec[0]->val = vec[1]->val;
//		vec[1]->val = temp;
//	}
//	
//public:
//	void recoverTree(TreeNode* root) {
//		IterativeInorder(root);
//		FindMistake();
//		Swap();
//	}
//};

class Solution {
private:
	TreeNode* pre;
	TreeNode* first;
	TreeNode* second;
	void InorderTraversal(TreeNode* root)
	{
		if (root == NULL)
			return;
		InorderTraversal(root->left);
		
		if (pre != NULL && first == NULL && pre->val >= root->val)
		{
			first = pre;
		}
		if (pre != NULL && first != NULL && pre->val >= root->val)
		{
			second = root;
		}
		pre = root;
		InorderTraversal(root->right);
	}

public:
	void recoverTree(TreeNode* root) {
		InorderTraversal(root);
		if (first != NULL && second != NULL)
		{
			int temp = first->val;
			first->val = second->val;
			second->val = temp;
		}
	}
};

class TestClass{
public:
	static TreeNode* GetTestData()
	{
		TreeNode* root0 = new TreeNode(0);
		TreeNode* root2 = new TreeNode(8);
		TreeNode* root3 = new TreeNode(3);
		TreeNode* root4 = new TreeNode(4);
		TreeNode* root5 = new TreeNode(5);
		TreeNode* root6 = new TreeNode(6);
		TreeNode* root7 = new TreeNode(7);
		TreeNode* root8 = new TreeNode(2);
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