#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

//******************************************************************************************
//Given a binary tree
//
//    struct TreeLinkNode {
//      TreeLinkNode *left;
//      TreeLinkNode *right;
//      TreeLinkNode *next;
//    }
//Populate each next pointer to point to its next right node. If there is no next right node, 
//the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//You may only use constant extra space.
//You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and
//every parent has two children).
//For example,
//Given the following perfect binary tree,
//         1
//       /  \
//      2    3
//     / \  / \
//    4  5  6  7
//After calling your function, the tree should look like:
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \  / \
//    4->5->6->7 -> NULL
//*********************************************************************************

//方法一：用最直观的想法，层序遍历，然后把每行的都连起来
//class Solution {
//
//private:
//	vector<vector<TreeLinkNode*>> result;
//
//	void recursiveLevelTraverse(TreeLinkNode* root, int level)
//	{
//		vector<int> row;
//		if (root == NULL)
//			return;
//		if (level == result.size())
//		{
//			result.push_back(vector<TreeLinkNode*>());
//		}
//
//		result[level].push_back(root);
//
//		recursiveLevelTraverse(root->left, level + 1);
//		recursiveLevelTraverse(root->right, level + 1);
//	}
//
//	void connectRightNode()
//	{
//		for (size_t i = 0; i < result.size(); i++)
//		{
//			for (size_t j = 0; j < result[i].size(); j++)
//			{
//				if (j != (result[i].size() - 1))
//					result[i][j]->next = result[i][j + 1];
//				else
//				{
//					result[i][j]->next = NULL;
//				}
//			}
//		}
//	}
//
//public:
//	void connect(TreeLinkNode *root) {
//		recursiveLevelTraverse(root, 0);
//		connectRightNode();
//	}
//};

//方法二：用另外一种方法递归求出来了
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
		{
			return;
		}
		if (root->left != NULL)
		{
			root->left->next = root->right;
			if (root->next != NULL)
			{
				root->right->next = root->next->left;
			}
			connect(root->left);
			connect(root->right);
		}
	}
};