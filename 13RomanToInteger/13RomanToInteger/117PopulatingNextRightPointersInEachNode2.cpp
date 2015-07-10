#include <iostream>
#include <vector>
#include <queue>
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

//���򣺣���������������������������������������������������������������
//������˼���������116�Ľ��������һģһ���ģ������е�Ч����Ȼ�ǵ���һЩ������ͨ���Ժ�ǿ
//����һ������ֱ�۵��뷨�����������Ȼ���ÿ�еĶ�������
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


//���������ο�116����ķ���ʵ��һ�飬���̫���۲���ʵ��
//class Solution {
//public:
//	void connect(TreeLinkNode *root) {
//		if (root == NULL)
//		{
//			return;
//		}
//		if (root->left != NULL && root->right != NULL)
//		{
//			root->left->next = root->right;
//			if (root->next != NULL)
//			{
//				root->right->next = root->next->left;
//			}
//			connect(root->left);
//			connect(root->right);
//		}
//	}
//};

//����������������ο�104BinaryTreeLevelOrderTraversal.cpp����һ��Count�������õ��������ڷ���һ

class Solution {
private:
	void levelOrderLink(TreeLinkNode* root) {
		queue<TreeLinkNode*> que;
		TreeLinkNode* pre = NULL;
		int count = 0;
		int currentLeft = 1;

		if (root == NULL)
			return;

		que.push(root);

		while (!que.empty())
		{
			TreeLinkNode* temp2 = que.front();
			que.pop();

			currentLeft--;

			if (temp2->left != NULL)
			{
				que.push(temp2->left);
				count++;

			}
			if (temp2->right != NULL)
			{
				que.push(temp2->right);
				count++;
			}

			if (pre != NULL)
			{
				pre->next = temp2;
			}

			pre = temp2;

			if (currentLeft == 0)
			{
				currentLeft = count;
				count = 0;
				pre = NULL;
			}
		}
	}
public:
	void connect(TreeLinkNode *root) {
		levelOrderLink(root);
	}
};