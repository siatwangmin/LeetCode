#include <iostream>
#include <vector>
#include <map>
#include "tree.h"

using namespace std;


//********************************Description******************************************************
//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
//between two nodes v and w as the lowest node in T that has both v and w as descendants 
//(where we allow a node to be a descendant of itself).”
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


//方法一：Time Out
//class Solution {
//private:
//	TreeNode* _lca;
//	TreeNode* _p;
//	TreeNode* _q;
//	bool _flag;
//
//	bool RecursiveFind(TreeNode* root, TreeNode* key)
//	{
//		bool result = false;
//		if (root == NULL)
//		{
//			return result;
//		}
//		if (root->val == key->val)
//		{
//			result = true;
//		}
//		if (!result)
//			result = RecursiveFind(root->left, key);
//		if (!result)
//			result = RecursiveFind(root->right, key);
//
//		return result;
//	}
//
//	void RecursiveLCA(TreeNode* root)
//	{
//		if (root == NULL)
//			return;
//		if (!_flag)
//			RecursiveLCA(root->left);
//		if (!_flag)
//			RecursiveLCA(root->right);
//
//		if (RecursiveFind(root, _q) && RecursiveFind(root, _p))
//		{
//			if (!_flag)
//			{
//				_lca = root;
//				_flag = true;
//			}
//
//		}
//	}
//public:
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		_p = p;
//		_q = q;
//		_lca = NULL;
//		_flag = false;
//		RecursiveLCA(root);
//		return _lca;
//	}
//
//};


//方法二：
//class Solution {
//public:
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//
//		unordered_map<TreeNode*, int> depth;
//		unordered_map<TreeNode*, TreeNode*> parent;
//		dfs(root, NULL, 0, depth, parent);
//		if (depth[p] < depth[q])
//			swap(p, q);
//		int d = depth[p] - depth[q];
//		for (int i = 0; i<d; i++)
//			p = parent[p];
//		while (p != q) {
//			q = parent[q];
//			p = parent[p];
//		}
//		return p;
//	}
//
//	void dfs(TreeNode* node, TreeNode* p, int d,
//		unordered_map<TreeNode*, int>& depth,
//		unordered_map<TreeNode*, TreeNode*>& parent) {
//		if (!node) return;
//		depth[node] = d;
//		parent[node] = p;
//		dfs(node->left, node, d + 1, depth, parent);
//		dfs(node->right, node, d + 1, depth, parent);
//	}
//};

//方法三
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || root == p || root == q)
		{
			return root;
		}

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left != NULL && right != NULL)
			return root;
		return left != NULL ? left : right;
	}
};

class TestClass{
public:
	TreeNode* getTestData()
	{
		TreeNode* root37 = new TreeNode(37);
		TreeNode* root_34 = new TreeNode(-34);
		TreeNode* root_48 = new TreeNode(-48);
		TreeNode* root_100 = new TreeNode(-100);
		TreeNode* root48 = new TreeNode(48);
		TreeNode* root_54 = new TreeNode(-54);
		TreeNode* root_71 = new TreeNode(-71);
		TreeNode* root_22 = new TreeNode(-22);
		TreeNode* root8 = new TreeNode(8);

		root_22->right = root8;

		root_54->left = root_71;
		root_54->right = root_22;

		root48->left = root_54;

		root_48->left = root_100;
		root_48->right = root48;

		root_34->right = root_100;

		root37->left = root_34;

		root37->right = root_48;
		return root37;
	}
};