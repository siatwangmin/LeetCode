//
// Created by wangmin on 7/25/18.
//
#include<vector>
#include <stack>
#include<gtest/gtest.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
private:
    vector<int> vec;
    stack<TreeNode*> s;
public:
//    vector<int> postorderTraversal(TreeNode* root){
//        if(!root)
//            return vec;
//        postorderTraversal(root->left);
//        postorderTraversal(root->right);
//        vec.push_back(root->val);
//        return vec;
//    }

    vector<int> postorderTraversal(TreeNode* root){
        while(root || !s.empty()){
            while(root){
                vec.insert(vec.begin(), root->val);
                s.push(root);
                root = root->right;
            }
            root = s.top();
            s.pop();
            root = root->left;
        }
        return vec;
    }
};


TEST(BinaryTreePostorderTraversalTest, NonNUllCase){
    Solution s;
    TreeNode* root1 = new TreeNode(1);
    TreeNode* root2 = new TreeNode(2);
    TreeNode* root3 = new TreeNode(3);
    root1->left = root2;
    root1->right = root3;
    vector<int> exp = {2, 3, 1};
    auto re = s.postorderTraversal(root1);
    for (int i = 0; i < re.size(); ++i) {
        EXPECT_EQ(exp[i], re[i]) << "differ at" << i;
    }
}

TEST(BinaryTreePostorderTraversalTest, HandleNUll){
    Solution s;
    EXPECT_EQ(0, s.postorderTraversal(NULL).size());
}
