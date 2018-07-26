//
// Created by wangmin on 7/26/18.
//

#include <vector>
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
    vector<long> vec_val;
    vector<long> vec_num;

    void dfs(TreeNode* root, int d) {
       if(root){
           if(vec_val.size() < d + 1){
               vec_val.push_back(root->val);
               vec_num.push_back(1);
           }else{
               vec_val[d]+=root->val;
               vec_num[d] += 1;
           }


           dfs(root->left, d + 1);
           dfs(root->right, d + 1);
       } else{
           return;
       }
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        size_t  n = vec_num.size();
        vector<double> res(n, 0.0);
        for (int i = 0; i < n; ++i) {
            res[i] = static_cast<double>(vec_val[i]) / vec_num[i];
        }
        return res;
    }
};

TEST(AverageOfLevelsTest, NotNullTest){
    Solution s;


}



