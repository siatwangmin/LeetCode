#include<iostream>
#include<vector>
#include<queue>
#include "tree.h"

using namespace std;

// 递归的方法,参考了https://leetcode.com/discuss/32042/6ms-simple-c-solution里面的经典方法
class Solution {

private:
	vector<vector<int>> result;
	
	void recuriveLevelTraverse(TreeNode* root, int level)
	{
		vector<int> row;
		if (root == NULL)
			return;
		if (level == result.size())
		{
			result.push_back(vector<int>());
		}
		if (level % 2 == 0)
		{
			result[level].push_back(root->val);
		}
		else
		{
			result[level].insert(result[level].begin(), root->val);
		}
		recuriveLevelTraverse(root->left, level + 1);
		recuriveLevelTraverse(root->right, level + 1);
	}

public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		
		recuriveLevelTraverse(root, 0);
		return result;

	}
};



//Time Out 版本，不过我还觉得写得可以 O(n)

//class Solution {
//public:
//	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//
//		vector<vector<int>> result;
//		vector<int> row;
//		queue<TreeNode*> que;
//
//		bool invertVector = false;
//
//		int count = 0;
//		int currentCount = 1;
//
//		if (root == NULL)
//		{
//			return result;
//		}
//
//		que.push(root);
//		
//		while (!que.empty())
//		{
//			TreeNode* temp = que.front();
//			que.pop();
//			row.push_back(temp->val);
//
//			currentCount--;
//
//			if (root->left != NULL)
//			{
//				que.push(root->left);
//				count++;
//			}
//			if (root->right != NULL)
//			{
//				que.push(root->right);
//				count++;
//			}
//
//			if (currentCount == 0)
//			{
//				if (invertVector)
//				{
//					reverse(row.begin(), row.end());
//				}
//				invertVector = !invertVector;
//				result.push_back(row);
//				row.clear();
//				currentCount = count;
//				count = 0;
//			}
//
//		}
//
//
//		return result;
//
//	}
//};