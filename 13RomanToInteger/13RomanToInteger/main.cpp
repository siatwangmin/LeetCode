#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>

#include "236LowestCommonAncestorofaBinaryTree.cpp"

using namespace std;

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> result;
	if (root == NULL)
		return result;

	result.push_back(root->val);

	vector<int> l = preorderTraversal(root->left);

	for (size_t i = 0; i < l.size(); i++)
	{
		result.push_back(l[i]);
	}

	vector<int> r = preorderTraversal(root->right);

	for (size_t i = 0; i < r.size(); i++)
	{
		result.push_back(r[i]);
	}

	return result;


}

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
	vector<int> temp(10);
	if (root == NULL)
	{
		return result;
	}
	vector<int> l = postorderTraversal(root->left);
	for (size_t i = 0; i < l.size(); i++)
	{
		result.push_back(l[i]);
	}
	vector<int> r = postorderTraversal(root->right);
	for (size_t i = 0; i < r.size(); i++)
	{
		result.push_back(r[i]);
	}
	result.push_back(root->val);
	return result;
}

class ConstructSolution {
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

		root->left = recursiveBuild(lpStart, lpOffset, liStart, liOffset);
		root->right = recursiveBuild(rpStart, rpOffset, riStart, riOffset);

		return root;


	}

public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		_inorder = inorder;
		_postorder = postorder;
		return recursiveBuild(0, _postorder.size() - 1, 0, _inorder.size() - 1);
	}
};

int main()
{
	TreeNode* root0 = new TreeNode(0);
	TreeNode* root2 = new TreeNode(2);
	TreeNode* root3 = new TreeNode(3);
	TreeNode* root4 = new TreeNode(4);
	TreeNode* root5 = new TreeNode(5);
	TreeNode* root6 = new TreeNode(6);
	TreeNode* root7 = new TreeNode(7);
	TreeNode* root8 = new TreeNode(8);
	TreeNode* root1 = new TreeNode(1);


	root2->left = root7;
	root2->right = root4;
	
	root5->left = root6;
	root5->right = root2;
	
	root1->left = root0;
	root1->right = root8;
	
	root3->left = root5;
	root3->right = root1;
	

	Solution mySolution = Solution();
	TreeNode* re = mySolution.lowestCommonAncestor(root3, root5, root1);
	cout << re->val;



	getchar();
	getchar();
	return 0;
}