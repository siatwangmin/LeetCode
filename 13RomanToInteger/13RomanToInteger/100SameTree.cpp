#include <iostream>
#include "tree.h"

using namespace std;


class Solution {
private:
	bool _result = true;
	void recursiveIsSame(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL)
		{
			return;
		}
		if (p == NULL && q != NULL)
		{
			_result = false;
			return;
		}
		if (p != NULL && q == NULL)
		{
			_result = false;
			return;
		}
			
		if (p->val != q->val)
			_result = false;

		recursiveIsSame(p->left, q->left);
		recursiveIsSame(p->right, q->right);
	}
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		recursiveIsSame(p, q);
		return _result;
	}
};