#include <iostream>
#include <vector>
#include "tree.h"
#include "linklist.h"

using namespace std;

//----------------------------------------Description-----------------------------------------------------------
//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//--------------------------------------------------------------------------------------------------------------

//方法一：最直观的想法，和108没什么区别
class Solution {
private :
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
	TreeNode* sortedListToBST(ListNode* head) {
		ListNode* cur = head;
		while (cur != NULL)
		{
			_nums.push_back(cur->val);
			cur = cur->next;
		}
		return constructBST(0, _nums.size() - 1);
	}
};


class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* a1 = new ListNode(1);
		return a1;
	}

	ListNode* GetTestData2()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);

		a1->next = a2;
		a2->next = a3;

		return a1;
	}

	ListNode* GetTestData3()
	{
		ListNode* a1 = new ListNode(1);
		ListNode* a2 = new ListNode(2);
		ListNode* a3 = new ListNode(3);
		ListNode* a4 = new ListNode(4);

		a1->next = a2;
		a2->next = a3;
		a3->next = a4;

		return a1;
	}
};