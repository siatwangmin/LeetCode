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
	

	Solution mySolution = Solution();
	TreeNode* re = mySolution.lowestCommonAncestor(root37, root_48, root8);
	cout << re->val;



	getchar();
	getchar();
	return 0;
}