#include<iostream>
#include<vector>
#include "tree.h"

using namespace std;


//*********************************Description*****************************************************
//*************************************************************************************************
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//*************************************************************************************************

//方法一
class Solution {
private:
	vector<int> _nums;
	TreeNode* constructBST(int start, int offset)
	{
		if (offset < 0)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(_nums[start + offset / 2]);
		root->left = constructBST(start, offset / 2 - 1);
		root->right = constructBST(start + offset / 2 + 1, offset - (offset / 2 + 1));
		return root;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		_nums = nums;
		return constructBST(0 , _nums.size() - 1);
	}
};

//方法二...........................