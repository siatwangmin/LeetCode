#include<iostream>
#include<vector>
#include"tree.h"
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		queue<TreeNode*> que;
		vector<int> row;
		bool serialNUll = false;

		if (root == NULL)
			return result;

		que.push(root);


		while (!que.empty())
		{
			TreeNode* temp2 = que.front();
			que.pop();
			

			if (temp2 != NULL)
			{
				if (temp2->left != NULL)
				{
					que.push(temp2->left);
				}
				else
				{
					que.push(NULL);
				}
				if (temp2->right != NULL)
				{
					que.push(temp2->right);
				}
				else
				{
					que.push(NULL);
				}
				row.push_back(temp2->val);
				serialNUll = false;
			}
			else
			{
				if (!serialNUll)
				{
					result.push_back(row);
					row.clear();
				}
				serialNUll = true;
			}
		}
		return result;
	}
};