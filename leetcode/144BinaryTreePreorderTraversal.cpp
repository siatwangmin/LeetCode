//
// Created by wangmin on 7/24/18.
//
// Definition for a binary tree node.
#include <vector>
#include <gtest/gtest.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
private:
	std::vector<int> res;
    std::stack<TreeNode*> stack;
public:
	std::vector<int> preorderTraversal(TreeNode* root){
		if(!root){
            return res;
        }
		res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
	}

    std::vector<int> iter_preorderTraversal(TreeNode* root){
        TreeNode* cur;
        stack.push(root);
        while(!stack.empty()){
            cur = stack.top();
            stack.pop();
            if(!cur){
                continue;
            }
            res.push_back(cur->val);
            stack.push(cur->right);
            stack.push(cur->left);
        }
        return res;
    }

};


TEST(BinaryTreePreorderTest, NoneZero) {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* root2 = new TreeNode(2);
    TreeNode* root3 = new TreeNode(3);
    root1->left = root2;
    root1->right = root3;
    Solution s;
    vector<int> re = s.preorderTraversal(root1);
    vector<int> er = {1, 2 ,3};
    for (int i = 0; i < re.size(); ++i) {
        EXPECT_EQ(re[i], er[i]) <<  "Vectors differ at " << i;
    }
}

TEST(BinaryTreePreorderTest, NULLTest) {
    Solution s;
    vector<int> re = s.preorderTraversal(NULL);
    EXPECT_EQ(re.size(), 0);
}


TEST(IterativeBinaryTreePreorderTest, NoneZero) {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* root2 = new TreeNode(2);
    TreeNode* root3 = new TreeNode(3);
    root1->left = root2;
    root1->right = root3;
    Solution s;
    vector<int> re = s.iter_preorderTraversal(root1);
    vector<int> er = {1, 2 ,3};
    for (int i = 0; i < re.size(); ++i) {
        EXPECT_EQ(re[i], er[i]) <<  "Vectors differ at " << i;
    }
}

TEST(IterativeBinaryTreePreorderTest, NULLTest) {
    Solution s;
    vector<int> re = s.iter_preorderTraversal(NULL);
    EXPECT_EQ(re.size(), 0);
}