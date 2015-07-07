#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		vector<int> temp(10);
		if (root == NULL)
		{
			return result;
		}
		vector<int> l = postorderTraversal(root->left);
		for (size_t i = 0; i < l.size(); i++)
		{
			result.push_back(l[i]);
		}
		vector<int> r = postorderTraversal(root->right);
		for (size_t i = 0; i < r.size(); i++)
		{
			result.push_back(r[i]);
		}
		result.push_back(root->val);
		return result;
	}
};

