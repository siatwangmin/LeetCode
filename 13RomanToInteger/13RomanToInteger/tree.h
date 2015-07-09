#ifndef _H_TREE
#define _H_TREE

#include <iostream>
#include "tree.h"

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	int val;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

#endif
