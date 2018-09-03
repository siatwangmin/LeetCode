#include <iostream>
#include "tree.h"
#include <vector>
#include <stack>

using namespace std;


//*************************Description**************************************
//Given a binary tree, return the preorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
//return [1,2,3].
//
//Note: Recursive solution is trivial, could you do it iteratively?
//*****************************************************************************

//Return : [6 2 0 4 3 5 8 7 9]
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
//	vector<int> preorderTraversal(TreeNode* root) {
//		vector<int> result;
//		if (root == NULL)
//			return result;
//		
//		result.push_back(root->val);
//
//		vector<int> l = preorderTraversal(root->left);
//
//		for (size_t i = 0; i < l.size(); i++)
//		{
//			result.push_back(l[i]);
//		}
//
//		vector<int> r = preorderTraversal(root->right);
//
//		for (size_t i = 0; i < r.size(); i++)
//		{
//			result.push_back(r[i]);
//		}
//
//		return result;
//
//			
//	}
//};


//方法二：迭代
class Solution {
private:
	TreeNode* cur;
	vector<int> result;
	stack<TreeNode*> sta;
public:
	vector<int> preorderTraversal(TreeNode* root) {
		cur = root;
		while (cur != NULL || !sta.empty())
		{
			while (cur != NULL)
			{
				result.push_back(cur->val);
				sta.push(cur);
				cur = cur->left;
			}
			cur = sta.top();
			sta.pop();
			cur = cur->right;
		}
		return result;
	}
};