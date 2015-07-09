#include <iostream>
#include "tree.h"

using namespace std;

//**********************************************************************
//Invert a binary tree.
//
//   4
//  / \
// 2   7
/// \ / \
//1 3 6   9
//to
//4
/// \
//7     2
/// \ / \
//9   6 3   1
//Trivia:
//This problem was inspired by this original tweet by Max Howell :
//Google : 90 % of our engineers use the software you wrote(Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
//***********************************************************************


//方法一：另外生成一个树，用来存储镜像后的树
class Solution{
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return NULL;
		}
		TreeNode* invertRoot = new TreeNode(root->val);

		invertRoot->right = invertTree(root->left);
		invertRoot->left = invertTree(root->right);

		return invertRoot;
	}
};

//！！！！！重要！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//方法二：通过指针，在原有的树的基础上改变树，这样返回的是原树，而且原树本身被镜像了，这就是指针的优点，同样也
//也不小心变成了一个小小的bug，在解决SymmetricTree的过程中。
//class Solution {
//public:
//	TreeNode* invertTree(TreeNode* root) {
//		if (root == NULL)
//		{
//			return NULL;
//		}
//		invertTree(root->left);
//		invertTree(root->right);
//
//		TreeNode* temp = root->left;
//		root->left = root->right;
//		root->right = temp;
//		return root;
//	}
//};




//int main()
//{
//	Solution mySolution = Solution();
//	TreeNode myTreeNode = TreeNode(1);
//	mySolution.invertTree(&myTreeNode);
//	getchar();
//	getchar();
//	return 0;
//}