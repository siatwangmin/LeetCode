#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;


class Solution {

private:
	vector<int> _preorder;
	vector<int> _inorder;
	

	TreeNode* recursiverBuild(int pStart, int pOffset, int iStart, int iOffset)
	{
		if (pOffset == -1)
			return NULL;
		TreeNode* root = new TreeNode(_preorder[pStart]);
		//vector<int>::iterator inorderM = find(_inorder.begin() + i_s, _inorder.begin() + i_e, root->val);
		//int inorderMPosition = inorderM - _inorder.begin();
		int mOffset;
		for (size_t i = iStart; i < iStart + iOffset + 1; i++)
		{
			if (root->val == _inorder[i])
			{
				mOffset = i - iStart;
				break;
			}
		}


		int lpStart = pStart + 1;
		int lpOffset = mOffset - 1;
		int rpStart = pStart + mOffset + 1;
		int rpOffset = pOffset - mOffset - 1;


		int liStart = iStart;
		int liOffset = mOffset - 1;
		int riStart = iStart + mOffset + 1;
		int riOffset = iOffset - mOffset - 1;


		root->left = recursiverBuild(lpStart, lpOffset, liStart, liOffset);
		root->right = recursiverBuild(rpStart, rpOffset, riStart, riOffset);

		return root;
	}
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		_preorder = preorder;
		_inorder = inorder;
		return recursiverBuild(0 , preorder.size() - 1, 0, inorder.size() - 1);
	}

};

//每次生成新的vector导致内存过多
//class Solution {
//
//
//public:
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		if (preorder.size() == 0)
//			return NULL;
//		TreeNode* root = new TreeNode(preorder[0]);
//		vector<int>::iterator inorderM = find(inorder.begin(), inorder.end(), root->val);
//		int inorderMPosition = inorderM - inorder.begin();
//		vector<int> leftInorder;
//		vector<int> rightInorder;
//		vector<int> leftpreorder;
//		vector<int> rightpreorder;
//
//		for (size_t i = 0; i < inorderMPosition; i++)
//		{
//			leftInorder.push_back(inorder[i]);
//		}
//		for (size_t i = inorderMPosition + 1; i < inorder.size(); i++)
//		{
//			rightInorder.push_back(inorder[i]);
//		}
//		for (size_t i = 1; i < inorderMPosition + 1; i++)
//		{
//			leftpreorder.push_back(preorder[i]);
//		}
//		for (size_t i = inorderMPosition + 1; i < preorder.size(); i++)
//		{
//			rightpreorder.push_back(preorder[i]);
//		}
//
//		root->left = buildTree(leftpreorder, leftInorder);
//		root->right = buildTree(rightpreorder, rightInorder);
//
//		return root;
//	}
//};


