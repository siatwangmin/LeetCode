#include <iostream>
#include <queue>
#include <vector>
#include "tree.h"
#include <string>
#include "link.h"

#include "237DeleteNodeinaLinkeList.cpp"


using namespace std;

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	
	node3->next = node4;
	node2->next = node3;
	node1->next = node2;

	Solution mySolution = Solution();
	mySolution.deleteNode(node3);

	getchar();
	getchar();
	return 0;
}