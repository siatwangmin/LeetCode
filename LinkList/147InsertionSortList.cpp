#include<iostream>
#include "linklist.h"

using namespace std;

//-------------Description ---------------
//Sort a linked list using insertion sort.
//----------------------------------------


class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* cur = head;
		ListNode* res = new ListNode(0);
		while (cur != NULL)
		{

			cur = cur->next;
		}
	}
};