#include<iostream>
#include<vector>
#include"tree.h"

using namespace std;

//用递归的方法
class Solution {
private:
	vector<vector<int>> result;
	void levelOrderTraversal(TreeNode* root, int level)
	{
		if (root == NULL)
			return;
		if (level == result.size())
		{
			result.push_back(vector<int>());
		}
		result[level].push_back(root->val);
		levelOrderTraversal(root->left, level + 1);
		levelOrderTraversal(root->right, level + 1);
	}
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		levelOrderTraversal(root, 0);
		reverse(result.begin(), result.end());
		return result;
	}
};

//考虑用迭代的方法实现.......