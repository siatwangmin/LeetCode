#include <iostream>
#include <vector>
#include <stack>
#include "tree.h"

using namespace std;

//递归的方法
//class Solution {
//private:
//	vector<int> result;
//
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		if (root == NULL)
//			return result;
//		inorderTraversal(root->left);
//		result.push_back(root->val);
//		inorderTraversal(root->right);
//		return result;
//
//	}
//};

//考虑用循环....


class Solution {
private:
	vector<int> result;
	stack<TreeNode*> sta;
	TreeNode* cur;

public:
	vector<int> inorderTraversal(TreeNode* root) {
		cur = root;
		while (cur != NULL || !sta.empty())
		{
			while (cur != NULL)
			{
				sta.push(cur);
				cur = cur->left;
			}
			cur = sta.top();
			sta.pop();
			result.push_back(cur->val);
			cur = cur->right;
		}
		return result;
	}
};

class TestClass{
public :
	static TreeNode* getTestData()
	{
		TreeNode* root0 = new TreeNode(0);
		TreeNode* root2 = new TreeNode(2);
		TreeNode* root3 = new TreeNode(3);
		TreeNode* root4 = new TreeNode(4);
		TreeNode* root5 = new TreeNode(5);
		TreeNode* root6 = new TreeNode(6);
		TreeNode* root7 = new TreeNode(7);
		TreeNode* root8 = new TreeNode(8);
		TreeNode* root9 = new TreeNode(9);

		root4->left = root3;
		root4->right = root5;

		root2->left = root0;
		root2->right = root4;

		root8->left = root7;
		root8->right = root9;

		root6->left = root2;
		root6->right = root8;

		return root6;	
	}
};