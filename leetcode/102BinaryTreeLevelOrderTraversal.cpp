//
// Created by wangmin on 7/26/18.
//

#include <vector>
#include <queue>
#include <gtest/gtest.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class Solution {
private:
    vector<vector<int>> vec;
    void recLevelTraver(TreeNode* root, int d){
        if(!root)
            return ;
        if(vec.size() == d){
            vector<int> tmp;
            tmp.push_back(root->val);
            vec.push_back(tmp);
        } else {
            vec[d].push_back(root->val);
        }
        recLevelTraver(root->left, d + 1);
        recLevelTraver(root->right, d + 1);
    }
public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        recLevelTraver(root, 0);
//        return vec;
//    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> vec;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root)
            return res;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp){
                vec.push_back(tmp->val);
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }

            }else{
                if(q.size() > 0){
                    q.push(NULL);
                }
                res.push_back(vec);
                vec.resize(0);
            }
        }
        return res;
    }
};

TEST(LevelOrderTraversalTest, NonNull){
    Solution s;
    TreeNode* root3  = new TreeNode(3);
    TreeNode* root9  = new TreeNode(9);
    TreeNode* root20 = new TreeNode(20);
    TreeNode* root15 = new TreeNode(15);
    TreeNode* root7  = new TreeNode(7);
    root3->left = root9;
    root3->right = root20;
    root20->left = root15;
    root20->right = root7;
    vector<vector<int>> res = s.levelOrder(root3);
    vector<vector<int>> exp;
    vector<int> e1 = {3};
    vector<int> e2 = {9, 20};
    vector<int> e3 = {15, 7};
    exp.push_back(e1);
    exp.push_back(e2);
    exp.push_back(e3);

//    for (int i = 0; i < res.sie; ++i) {
//
//    }
    EXPECT_EQ(exp, res);



}

TEST(LevelOrderTraversalTest, Null){
    Solution s;
    vector<vector<int>> res = s.levelOrder(NULL);
    vector<vector<int>> exp;
    EXPECT_EQ(exp, res);



}



