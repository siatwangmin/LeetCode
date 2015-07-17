#ifndef _LINK_H_
#define _LINK_H_
#include <iostream>

struct DoubleListNode {
	int val;
	DoubleListNode *next;
	DoubleListNode *pre;
	
	DoubleListNode(int x) : val(x), next(NULL), pre(NULL){}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


#endif