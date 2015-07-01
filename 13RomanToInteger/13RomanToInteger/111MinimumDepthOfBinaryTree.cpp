#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		else
		{
			int l = minDepth(root->left);
			int r = minDepth(root->right);
			if (r > 0 && l > 0)
			{
				return 1 + (l > r ? r : l);
			}
			else
			{
				return 1 + r + l;
			}
		}
	}
};