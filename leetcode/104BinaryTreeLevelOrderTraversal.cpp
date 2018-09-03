#include<iostream>
#include<vector>
#include"tree.h"
#include <queue>

using namespace std;


// 参考问题BinaryTreeZigzagLevelOrderTraveral写了一个递归的方法，O(n)
//class Solution {
//
//private:
//	vector<vector<int>> result;
//
//	void recuriveLevelTraverse(TreeNode* root, int level)
//	{
//		vector<int> row;
//		if (root == NULL)
//			return;
//		if (level == result.size())
//		{
//			result.push_back(vector<int>());
//		}
//
//		result[level].push_back(root->val);
//
//		recuriveLevelTraverse(root->left, level + 1);
//		recuriveLevelTraverse(root->right, level + 1);
//	}
//
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//
//		recuriveLevelTraverse(root, 0);
//		return result;
//
//	}
//};


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		queue<TreeNode*> que;
		vector<int> row;
		int count = 0;
		int currentLeft = 1;

		if (root == NULL)
			return result;

		que.push(root);

		while (!que.empty())
		{
			TreeNode* temp2 = que.front();
			que.pop();

			row.push_back(temp2->val);
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

			if (currentLeft == 0)
			{
				result.push_back(row);
				row.clear();
				currentLeft = count;
				count = 0;
			}
		}
		return result;
	}
};