//
// Created by wangmin on 7/26/18.
//
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> vec1;
    vector<int> vec2;
    void postorderTraversal(TreeNode* root, vector<int>& vec){
        if(!root)
            return;
        postorderTraversal(root->left, vec);
        postorderTraversal(root->right,vec);
        if(!root->left && !root->right){
            vec.push_back(root->val);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        postorderTraversal(root1, vec1);
        postorderTraversal(root2, vec2);
        size_t n1 = vec1.size();
        size_t n2 = vec2.size();
        if(n1 == n2){

            for (int i = 0; i < n1; ++i) {
                if(vec1[i] == vec2[i]){
                    continue;
                }
                else
                    return false;
            }
        }
        else{
            return false;
        }
        return true;
    }
};

