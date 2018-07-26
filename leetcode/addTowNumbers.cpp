//
// Created by wangmin on 7/12/18.
//

#include "iostream"
/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*

 class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* curL1Length = l1;
		ListNode* curL2Length = l2;


		while (curL1Length != NULL  && curL2Length != NULL)
		{
			curL1Length = curL1Length->next;
			curL2Length = curL2Length->next;
		}

		ListNode* curL1 = curL1Length ? l1 : l2;
		ListNode* curL2 = curL1Length ? l2 : l1;

		ListNode* preL1 = NULL;
		ListNode* preL2 = NULL;
		int carry = 0;
		while (curL1 != NULL)
		{
			if (curL2 != NULL)
			{
				curL1->val += curL2->val + carry;
				preL2 = curL2;
				curL2 = curL2->next;
			}
			else
			{
				curL1->val += carry;
			}
			carry = curL1->val / 10;
			curL1->val = curL1->val % 10;

			preL1 = curL1;
			curL1 = curL1->next;
		}

		if (carry != 0 && preL1 != NULL)
		{
			preL1->next = new ListNode(carry);
		}

		return curL1Length ? l1 : l2;
	}
};
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(0);
        ListNode* ptr = root;
        ListNode* l1_ptr = l1;
        ListNode* l2_ptr = l2;


        int carry = 0;

        ptr->val = (l1_ptr->val + l2_ptr ->val + carry) % 10;
        carry = (l1_ptr->val + l2_ptr ->val + carry) / 10;
        l1_ptr = l1_ptr->next;
        l2_ptr = l2_ptr->next;

        while(true)
        {
            if(l1_ptr )
            {
                ListNode* tmp = new ListNode(0);
                ptr->next = tmp;
                ptr = ptr->next;
                if(l2_ptr)
                {
                    ptr->val = (l1_ptr->val + l2_ptr ->val + carry) % 10;
                    carry = (l1_ptr->val + l2_ptr ->val + carry) / 10;
                    l2_ptr = l2_ptr->next;
                }
                else
                {
                    ptr->val = (l1_ptr->val + carry) % 10;
                    carry = (l1_ptr->val  + carry) / 10;
                }
                l1_ptr = l1_ptr->next;
            }
            else if(l2_ptr)
            {
                ListNode* tmp = new ListNode(0);
                ptr->next = tmp;
                ptr = ptr->next;

                ptr->val = (l2_ptr->val + carry) % 10;
                carry = (l2_ptr->val  + carry) / 10;
                l2_ptr = l2_ptr->next;
            }
            else
            {
                if(carry != 0)
                {
                    ListNode* tmp = new ListNode(0);
                    ptr->next = tmp;
                    ptr = ptr->next;
                    ptr->val = carry;
                }
                break;
            }
        }
        return root;
    }
};


