#include <iostream>
#include <vector>
#include <stack>
#include "tree.h"

using namespace std;

//*************************Description**********************
//Given a binary tree, flatten it to a linked list in-place.
//
//For example,
//Given
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
//The flattened tree should look like:
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
//**********************************************************
class TestClass{
public:
	TreeNode* GetTestData()
	{
		TreeNode* root1 = new TreeNode(1);
		TreeNode* root2 = new TreeNode(2);
		TreeNode* root3 = new TreeNode(3);
		TreeNode* root4 = new TreeNode(4);
		TreeNode* root5 = new TreeNode(5);
		TreeNode* root6 = new TreeNode(6);
		
		root2->left = root3;
		root2->right = root4;
		
		root5->right = root6;

		root1->left = root2;
		root1->right = root5;
		return root1;
	}
};

class Solution {
private:
	TreeNode* cur;
	vector<TreeNode*> vec;
	stack<TreeNode*> sta;
	void IterativePreorder(TreeNode* root)
	{
		cur = root;
		while (cur != NULL || !sta.empty())
		{
			while (cur != NULL)
			{
				vec.push_back(cur);
				sta.push(cur);
				cur = cur->left;
			}
			cur = sta.top();
			sta.pop();
			cur = cur->right;
		}
	}
	void Flat()
	{
		if (vec.size() == 0)
		{
			return;
		}
		for (size_t i = 0; i < vec.size() - 1; i++)
		{
			vec[i]->right = vec[i + 1];
			vec[i]->left = NULL;
		}
		vec[vec.size() - 1]->left = NULL;
	}

public:
	void flatten(TreeNode* root) {
		IterativePreorder(root);
		Flat();
	}
};