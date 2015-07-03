#include <iostream>
#include "tree.h"


using namespace std;



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