#include<iostream>
#include "tree.h"
#include <vector>
#include <queue>
#include <stack>

#include "106ConstructBinaryTreefromInorderandPostorderTraversal.cpp"

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


int main()
{
	vector<int> preorder;
	vector<int> inorder;
	vector<int> postorder;


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

	postorder.push_back(4);
	postorder.push_back(1);
	postorder.push_back(3);
	postorder.push_back(10);
	postorder.push_back(11);
	postorder.push_back(8);
	postorder.push_back(2);
	postorder.push_back(7);

	Solution mySolution = Solution();
	TreeNode* test = mySolution.buildTree(inorder, postorder);

	vector<int> re = preorderTraversal(test);
	vector<int> pt = postorderTraversal(test);

	getchar();
	getchar();
	return 0;
}