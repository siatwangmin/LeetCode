#include <iostream>
#include "tree.h"

using namespace std;

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return NULL;
		}
		invertTree(root->left);
		invertTree(root->right);

		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		return root;
	}
};

//int main()
//{
//	Solution mySolution = Solution();
//	TreeNode myTreeNode = TreeNode(1);
//	mySolution.invertTree(&myTreeNode);
//	getchar();
//	getchar();
//	return 0;
//}