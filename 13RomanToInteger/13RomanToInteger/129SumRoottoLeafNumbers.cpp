#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;


//**********************************Description********************************************************
//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root-to-leaf numbers.
//
//For example,
//
//    1
//   / \
//  2   3
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//
//Return the sum = 12 + 13 = 25.
//******************************************************************************************************

class Solution {
private:
	vector<int> vec;
	int sum;
	void RecursiveSum(TreeNode* root)
	{
		int num = 0;
		if (root == NULL)
			return;
		vec.push_back(root->val);

		
		if (root->left == NULL  && root->right == NULL)
		{
			for (size_t i = 0; i < vec.size(); i++)
			{
				num = num * 10 + vec[i];
			}
			sum += num;
		}

		RecursiveSum(root->left);
		RecursiveSum(root->right);
		vec.pop_back();

	}
public:
	int sumNumbers(TreeNode* root) {
		sum = 0;
		RecursiveSum(root);
		return sum;
	}
};