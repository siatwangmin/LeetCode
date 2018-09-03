#include <iostream>
#include <vector>
#include "tree.h"
#include <stack>

using namespace std;

//****************************Description***********************************
//Given a binary tree, return the postorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
//return [3,2,1].
//*****************************************************************************


//Return : [0 3 5 4 2 7 9 8 6]
class TestClass{
public:
	static TreeNode* GetTestData()
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

//方法一：递归
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		vector<int> result;
//		vector<int> temp(10);
//		if (root == NULL)
//		{
//			return result;
//		}
//		vector<int> l = postorderTraversal(root->left);
//		for (size_t i = 0; i < l.size(); i++)
//		{
//			result.push_back(l[i]);
//		}
//		vector<int> r = postorderTraversal(root->right);
//		for (size_t i = 0; i < r.size(); i++)
//		{
//			result.push_back(r[i]);
//		}
//		result.push_back(root->val);
//		return result;
//	}
//};


//方法二：迭代....这个方法可以用来写 前序 但是不能用来写中序
class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		stack<TreeNode*> nodeStack;
		vector<int> result;
		//base case
		if (root == NULL)
			return result;
		nodeStack.push(root);
		while (!nodeStack.empty())
		{
			TreeNode* node = nodeStack.top();
			result.push_back(node->val);
			nodeStack.pop();
			if (node->left)
				nodeStack.push(node->left);
			if (node->right)
				nodeStack.push(node->right);
		}
		reverse(result.begin(), result.end());
		return result;

	}
};