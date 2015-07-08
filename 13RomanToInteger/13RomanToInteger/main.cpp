#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>

#include "105ConstructBinaryTreefromPreorderandInorderTraversal.cpp"

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


int main()
{
	vector<int> preorder;
	vector<int> inorder;
	preorder.push_back(7);
	preorder.push_back(10);
	preorder.push_back(4);
	preorder.push_back(3);
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(8);
	preorder.push_back(11);

	inorder.push_back(4);
	inorder.push_back(10);
	inorder.push_back(3);
	inorder.push_back(1);
	inorder.push_back(7);
	inorder.push_back(11);
	inorder.push_back(8);
	inorder.push_back(2);

	Solution mySolution = Solution();
	TreeNode* test = mySolution.buildTree(preorder, inorder);

	vector<int> re = preorderTraversal(test);

	getchar();
	getchar();
	return 0;
}