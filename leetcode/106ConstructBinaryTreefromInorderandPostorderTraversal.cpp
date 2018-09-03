#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

class Solution {
private:
	vector<int> _inorder;
	vector<int> _postorder;

	TreeNode* recursiveBuild(int pStart, int pOffset, int iStart, int iOffset)
	{
		if (pOffset == -1)
			return NULL;
		TreeNode* root = new TreeNode(_postorder[pStart + pOffset]);
		
		int mOffset;
		for (size_t i = iStart; i < iStart + iOffset + 1; i++)
		{
			if (root->val == _inorder[i])
			{
				mOffset = i - iStart;
				break;
			}
		}

		int lpStart = pStart;
		int lpOffset = mOffset - 1;
		int rpStart = pStart + mOffset;
		int rpOffset = pOffset - mOffset - 1;

		int liStart = iStart;
		int liOffset = mOffset - 1;
		int riStart = iStart + mOffset + 1;
		int riOffset = iOffset - mOffset - 1;

		root->left = recursiveBuild(lpStart , lpOffset, liStart, liOffset);
		root->right = recursiveBuild(rpStart, rpOffset, riStart, riOffset);

		return root;

		
	}

public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		_inorder = inorder;
		_postorder = postorder;
		return recursiveBuild(0, _postorder.size() -1 , 0, _inorder.size() - 1);
	}
};