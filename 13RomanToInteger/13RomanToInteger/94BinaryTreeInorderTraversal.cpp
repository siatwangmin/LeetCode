#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

//递归的方法
class Solution {
private:
	vector<int> result;

public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == NULL)
			return result;
		inorderTraversal(root->left);
		result.push_back(root->val);
		inorderTraversal(root->right);
		return result;

	}
};

//考虑用循环....