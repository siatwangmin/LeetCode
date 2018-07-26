//
// Created by wangmin on 7/19/18.
//

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* first = head;
        if(!first || !first->next){
            return first;
        }
        ListNode* second = first -> next;
        first->next = swapPairs(second->next);
        second->next = first;
        return second;
    }

    ListNode* swapPairs2(ListNode* head)
    {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* tmp;
        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode* pre = res;

        while(first && first->next) {

            second = first->next;
            tmp = second->next;
            second->next = first;
            first->next = tmp;
            pre->next = second;
            pre = first;
            first = tmp;
        }
        return res->next;
    }


};

void test1()
{
    ListNode* root0 = new ListNode(1);
    ListNode* root1 = new ListNode(2);
    ListNode* root2 = new ListNode(3);
    ListNode* root3 = new ListNode(4);
    ListNode* root4 = new ListNode(5);
    ListNode* root5 = new ListNode(6);
    root0->next = root1;
    root1->next = root2;
    root2->next = root3;
    root3->next = root4;
    root4->next = root5;
    Solution s;
    auto res = s.swapPairs(root0);
    std::cout << res->val;
    res = res->next;
    while(res)
    {
        std::cout << "->" << res->val;
        res = res->next;
    }

}

void test2()
{
    ListNode* root0 = new ListNode(1);
    ListNode* root1 = new ListNode(2);
    ListNode* root2 = new ListNode(3);
    ListNode* root3 = new ListNode(4);
    ListNode* root4 = new ListNode(5);
    ListNode* root5 = new ListNode(6);
    root0->next = root1;
    root1->next = root2;
    root2->next = root3;
    root3->next = root4;
    root4->next = root5;
    Solution s;
    auto res = s.swapPairs2(root0);
    std::cout << res->val;
    res = res->next;
    while(res)
    {
        std::cout << "->" << res->val;
        res = res->next;
    }

}
