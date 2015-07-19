#include <iostream>
#include <vector>
#include "linklist.h"

using namespace std;

//******************   Description   **************************
//Given a singly linked list, determine if it is a palindrome.
//
//Follow up:
//Could you do it in O(n) time and O(1) space?
//**************************************************************

//����һ����ֱ�۵��뷨������û������O(1) space������ 28ms
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		vector<int> vec;
		ListNode* cur = head;
		while (cur != NULL)
		{
			vec.push_back(cur->val);
			cur = cur->next;
		}
		
		for (size_t i = 0; i < vec.size()/2; i++)
		{
			if (vec[i] != vec[vec.size() - 1 - i])
				return false;
		}
		return true;
	}
};

//����������������
//class Solution {
//public:
//	bool isPalindrome(ListNode* head) {
//		
//	}
//};

class TestClass{
public:
	ListNode* GetTestData1()
	{
		ListNode* node1 = new ListNode(1);
		ListNode* node2 = new ListNode(2);
		ListNode* node3 = new ListNode(3);
		ListNode* node4 = new ListNode(2);
		ListNode* node5 = new ListNode(1);

		node1->next = node2;
		node2->next = node3;
		node3->next = node4;
		node4->next = node5;

		return node1;
	}
	ListNode* GetTestData2()
	{
		ListNode* node1 = new ListNode(1);
		ListNode* node2 = new ListNode(1);
		ListNode* node3 = new ListNode(3);
		ListNode* node4 = new ListNode(2);
		ListNode* node5 = new ListNode(1);

		node1->next = node2;
		node2->next = node3;
		node3->next = node4;
		node4->next = node5;

		return node1;
	}
};