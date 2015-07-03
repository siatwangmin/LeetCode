#include <iostream>
#include "tree.h"

using namespace std;


class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		else
		{
			int l = maxDepth(root->left);
			int r = maxDepth(root->right);
			return 1 + (l > r ? l : r);
		}
	}
};