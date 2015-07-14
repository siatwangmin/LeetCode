#include<iostream>
#include "tree.h"
#include <vector>

using namespace std;


//******************Description****************************************
//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia:
//In a complete binary tree every level, except possibly the last,
//is completely filled, and all nodes in the last level are as far 
//left as possible. It can have between 1 and 2h nodes inclusive
//at the last level h.
//********************************************************************

//方法一：递归遍历所有的 Time Out；
//class Solution {
//private:
//	int count;
//
//	void RecursiveCount(TreeNode* root)
//	{
//		if (root == NULL)
//			return;
//		count++;
//		RecursiveCount(root->left);
//		RecursiveCount(root->right);
//	}
//
//public:
//	int countNodes(TreeNode* root) {
//		count = 0;
//		RecursiveCount(root);
//		return count;
//	}
//};


class Solution {
private:
	vector<int> vec;
	int maxHeight = -1;
	int lastLevelCount = 0;
	bool flag = false;
	void Recursive(TreeNode* root)
	{
		if (root == NULL)
			return;
		vec.push_back(root->val);
		if(!flag)
			Recursive(root->left);
		if(!flag)
			Recursive(root->right);

		if (maxHeight == -1)
		{
			maxHeight = vec.size();
			lastLevelCount++;
		}
		else
		{
			if (vec.size() < maxHeight)
			{
				flag = true;
				return;
			}
				
			lastLevelCount++;
		}
		vec.pop_back();	
	}
public:
	int countNodes(TreeNode* root) {
		Recursive(root);
		cout << maxHeight << '\t' << lastLevelCount << endl;
		return pow(2, maxHeight) - 1 + lastLevelCount;
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

		root2->left = root0;
		root2->right = root4;

		root8->left = root7;
		root8->right = root9;

		root6->left = root2;
		root6->right = root8;

		return root6;
	}
};