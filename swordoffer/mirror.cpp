//
// Created by wangmin on 7/14/18.
//

#include <iostream>
#include <queue>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
private:
    std::queue<TreeNode*> queue;
public:
    void Mirror(TreeNode *pRoot) {
        TreeNode* ptr;
        TreeNode* tmp = pRoot;
        queue.push(pRoot);
        while((ptr = queue.front()) != NULL)
        {
            if(ptr->left)
                queue.push(ptr->left);
            if(ptr->right)
                queue.push(ptr->right);

            tmp = ptr->right;
            ptr->right = ptr->left;
            ptr->left = tmp;
            queue.pop();
        }


    }
};

int main() {
    TreeNode* root  = new TreeNode(8);
    TreeNode* root6 = new TreeNode(6);
    TreeNode* root10 = new TreeNode(10);
    TreeNode* root5 = new TreeNode(5);
    TreeNode* root7 = new TreeNode(7);
    TreeNode* root9 = new TreeNode(9);
    TreeNode* root11 = new TreeNode(11);
    root->left = root6;
    root->right = root10;
    root6->left = root5;
    root6->right = root7;
    root10->left = root9;
    root10->right = root11;

    Solution s;
    s.Mirror(NULL);

//    ptr = ptr->next;
//    while(ptr)
//    {
//        std::cout << "->" << ptr->val;
//        ptr = ptr->next;
//
//    }
    std::cout << "hello" << std::endl;
    return 0;
}
