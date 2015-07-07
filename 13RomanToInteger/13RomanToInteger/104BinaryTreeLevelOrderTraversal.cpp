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
		queue<int> flag;
		int count = 1;

		if (root == NULL)
			return result;

		que.push(root);
		flag.push(count);

		count++;

		while (!que.empty())
		{
			TreeNode* temp2 = que.front();
			que.pop();


			if (temp2->left != NULL)
			{
				flag.push(count);
				que.push(temp2->left);
			}
			if (temp2->right != NULL)
			{
				flag.push(count);
				que.push(temp2->right);
			}
			
			count++;

		}

		return result;

			
	}
};