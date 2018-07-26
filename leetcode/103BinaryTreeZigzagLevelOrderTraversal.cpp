//
// Created by wangmin on 7/26/18.
//

#include <vector>
#include <queue>
#include <gtest/gtest.h>

using namespace std;
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
private:
    vector<vector<int>> vec;
    void bfs(TreeNode*root , int depth){
        if(!root)
            return;

        if(vec.size() < depth + 1) {
            vector<int> tmp;
            tmp.push_back(root->val);
            vec.push_back(tmp);
        }
        else{
            if(depth % 2 == 0){
                vec[depth].push_back(root->val);
            }
            else{
                vec[depth].insert(vec[depth].begin(),root->val);
            }
        }
        bfs(root->left, depth + 1);
        bfs(root->right, depth+1);
    }

public:
//    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//        bfs(root, 0);
//        return vec;
//    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> vec;
        if(!root)
            return res;
        q.push(root);
        q.push(NULL);

        int d = 0;
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t){
                if(d % 2 == 0)
                    vec.push_back(t->val);
                else
                    vec.insert(vec.begin(), t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }else{
                if(q.size() > 0){
                    q.push(NULL);
                }
//                if(d % 2)
//                    std::reverse(vec.begin(),vec.end());
                d++;

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
    vector<vector<int>> res = s.zigzagLevelOrder(root3);
    vector<vector<int>> exp;
    vector<int> e1 = {3};
    vector<int> e2 = {20, 9};
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
    vector<vector<int>> exp;
    EXPECT_EQ(exp, s.zigzagLevelOrder(NULL));

}



