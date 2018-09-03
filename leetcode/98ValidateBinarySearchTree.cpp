//
// Created by wangmin on 7/27/18.
//

#include <vector>
#include <stack>
#include <gtest/gtest.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//this is just a transformation of inorderTraversal
class Solution {
private:
    vector<int> vec;
    bool res = true;
    void recInorderTraversal(TreeNode* root) {
        if (res == false) {
            return;
        }
        if (!root) {
            return;
        }
        recInorderTraversal(root->left);
        size_t n = vec.size();
        if (n != 0) {
            if (vec[n - 1] >= root->val) {
                res = false;
            }
        }
        vec.push_back(root->val);
        recInorderTraversal(root->right);
    }

    bool iterInorderTraversal(TreeNode* root){
        stack<TreeNode*> sta;
        bool isInit = false;
        int prev = 0;
        while(root || !sta.empty()) {
            while (root) {
                sta.push(root);
                root = root->left;
            }
            root = sta.top();
            sta.pop();
            if (isInit && (prev >= root->val)) {
                return false;
            }
            isInit = true;
            prev = root->val;
            root = root->right;
        }
        return true;
    }



public:
    bool isValidBST(TreeNode* root) {
//            rec_inorderTraversal(root);
        return iterInorderTraversal(root);
    }
};



// The fixture for testing class Foo.
class IsValidBSTTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    IsValidBSTTest() {
        // You can do set-up work for each test here.
        TreeNode* node1 = new TreeNode(1);
        TreeNode* node2 = new TreeNode(2);
        TreeNode* node3 = new TreeNode(3);
        TreeNode* node4 = new TreeNode(4);
        TreeNode* node5 = new TreeNode(5);
        TreeNode* node6 = new TreeNode(6);
        TreeNode* node7 = new TreeNode(7);

        this->root_null_ = NULL;
        this->root_not_bst_ = new TreeNode(1);
        root_not_bst_->left = new TreeNode(2);
        root_not_bst_->right = new TreeNode(3);

        this->root_bst_ = node4;
        node4->left = node2;
        node2->left = node1;
        node2->right = node3;
        node4->right = node6;
        node6->left = node5;
        node6->right = node7;
    }

    ~IsValidBSTTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

//public:
    Solution s;
    TreeNode* root_bst_;
    TreeNode* root_not_bst_;
    TreeNode* root_null_;
};

TEST_F(IsValidBSTTest, BSTTEST){
    EXPECT_TRUE(s.isValidBST(root_bst_));
}

TEST_F(IsValidBSTTest, NotBSTTest){
    EXPECT_FALSE(s.isValidBST(root_not_bst_));
}
TEST_F(IsValidBSTTest, BSTNULLTest){
    EXPECT_TRUE(s.isValidBST(root_null_));
}