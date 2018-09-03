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
//Google : 90 % of our engineers use the software you wrote(Homebrew), but you can��t invert a binary tree on a whiteboard so fuck off.
//***********************************************************************


//����һ����������һ�����������洢��������
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

//������������Ҫ������������������������������������������������������������������������
//��������ͨ��ָ�룬��ԭ�е����Ļ����ϸı������������ص���ԭ��������ԭ�����������ˣ������ָ����ŵ㣬ͬ��Ҳ
//Ҳ��С�ı����һ��СС��bug���ڽ��SymmetricTree�Ĺ����С�
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