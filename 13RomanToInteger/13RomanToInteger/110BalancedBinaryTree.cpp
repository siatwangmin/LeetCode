#include <iostream>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
		{
			return true;
		}

		if (!isBalanced(root->left))
		{
			return false;
		}
		if (!isBalanced(root->right))
		{
			return false;
		}


		//方法一：判断左边的深度和右边的深度之差
		if (abs(Depth(root->left) - Depth(root->right)) < 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Depth(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int l = Depth(root->left);
		int r = Depth(root->right);
		return 1 + (l > r ? l : r);
	}

};


int main()
{
	return 0;
}
