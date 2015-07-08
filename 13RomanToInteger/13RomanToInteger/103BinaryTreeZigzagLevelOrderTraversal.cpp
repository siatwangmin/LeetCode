#include<iostream>
#include<vector>
#include<queue>
#include "tree.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		vector<vector<int>> result;
		vector<int> row;
		queue<TreeNode*> que;

		bool invertVector = false;

		int count = 0;
		int currentCount = 1;

		if (root == NULL)
		{
			return result;
		}

		que.push(root);
		
		while (!que.empty())
		{
			TreeNode* temp = que.front();
			que.pop();
			row.push_back(temp->val);

			currentCount--;

			if (root->left != NULL)
			{
				que.push(root->left);
				count++;
			}
			if (root->right != NULL)
			{
				que.push(root->right);
				count++;
			}

			if (currentCount == 0)
			{
				if (invertVector)
				{
					reverse(row.begin(), row.end());
				}
				invertVector = !invertVector;
				result.push_back(row);
				row.clear();
				currentCount = count;
				count = 0;
			}

		}


		return result;

	}
};