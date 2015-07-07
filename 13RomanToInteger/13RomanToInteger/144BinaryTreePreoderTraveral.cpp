#include <iostream>
#include "tree.h"
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		
		result.push_back(root->val);

		vector<int> l = preorderTraversal(root->left);

		for (size_t i = 0; i < l.size(); i++)
		{
			result.push_back(l[i]);
		}

		vector<int> r = preorderTraversal(root->right);

		for (size_t i = 0; i < r.size(); i++)
		{
			result.push_back(r[i]);
		}

		return result;

			
	}
};