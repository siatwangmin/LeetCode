#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

//******************************************************************************************
//Follow up for problem "Populating Next Right Pointers in Each Node".
//
//What if the given tree could be any binary tree? Would your previous solution still work?
//
//Note:
//
//You may only use constant extra space.
//For example,
//Given the following binary tree,
//         1
//       /  \
//      2    3
//     / \    \
//    4   5    7
//After calling your function, the tree should look like:
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \    \
//    4-> 5 -> 7 -> NULL
//*********************************************************************************

//感悟：！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//很有意思这个方法和116的解决方法是一模一样的，其运行的效率虽然是低了一些，但是通用性很强
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
		if (root->left != NULL && root->right != NULL)
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