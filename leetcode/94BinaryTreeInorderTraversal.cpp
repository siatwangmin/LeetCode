//
// Created by wangmin on 7/25/18.
//
#include<gtest/gtest.h>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
private:
    vector<int> res;
    stack<TreeNode*> s;

public:
    vector<int> inorderTraversal(TreeNode* root){
        if(!root){
            return res;
        }
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }

    vector<int> iter_inorderTraversal(TreeNode* root){
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

TEST(BinaryTreeInoderTest, HandleNonNUll){
    Solution s;
    TreeNode* root1 = new TreeNode(1);
    TreeNode* root2 = new TreeNode(2);
    TreeNode* root3 = new TreeNode(3);
    root1->left = root2;
    root1->right = root3;
    vector<int> exp = {2, 1, 3};
    auto re = s.inorderTraversal(root1);
    for (int i = 0; i < re.size(); ++i) {
        EXPECT_EQ(exp[i], re[i]) << "differ at" << i;
    }
}

TEST(BinaryTreeInoderTest, HandleNUll){
    Solution s;
    EXPECT_EQ(0, s.inorderTraversal(NULL).size());
}


TEST(BinaryTreeInoderTest, Iter_HandleNonNUll){
    Solution s;
    TreeNode* root1 = new TreeNode(1);
    TreeNode* root2 = new TreeNode(2);
    TreeNode* root3 = new TreeNode(3);
    root1->left = root2;
    root1->right = root3;
    vector<int> exp = {2, 1, 3};
    auto re = s.iter_inorderTraversal(root1);
    for (int i = 0; i < re.size(); ++i) {
        EXPECT_EQ(exp[i], re[i]) << "differ at" << i;
    }
}

TEST(BinaryTreeInoderTest, Iter_HandleNUll){
    Solution s;
    EXPECT_EQ(0, s.iter_inorderTraversal(NULL).size());
}

