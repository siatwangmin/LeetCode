#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;


//********************************Description******************************************************
//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined 
//between two nodes v and w as the lowest node in T that has both v and w as descendants 
//(where we allow a node to be a descendant of itself).¡±
//
//        _______3______
//       /              \
//    ___5__          ___1__
//   /      \        /      \
//   6      _2       0       8
//         /  \
//         7   4
//For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA 
//of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
//****************************************************************************************************

class Solution {
private:
	TreeNode* _lca;
	TreeNode* _p;
	TreeNode* _q;
	bool _flag;

	bool RecursiveFind(TreeNode* root, TreeNode* key)
	{
		bool result = false;
		if (root == NULL)
		{
			return result;
		}

		if (root->val == key->val)
		{
			result = true;
		}
		if (!result)
			result = RecursiveFind(root->left, key);
		if (!result)
			result = RecursiveFind(root->right, key);

		return result;
	}

	void RecursiveLCA(TreeNode* root)
	{
		if (root == NULL)
			return;
		if (!_flag)
			RecursiveLCA(root->left);
		if (!_flag)
			RecursiveLCA(root->right);

		if (RecursiveFind(root, _q) && RecursiveFind(root, _p))
		{
			if (!_flag)
			{
				_lca = root;
				_flag = true;
			}

		}
	}
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		_p = p;
		_q = q;
		_lca = NULL;
		_flag = false;
		RecursiveLCA(root);
		return _lca;
	}

};