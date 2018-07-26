//
// Created by wangmin on 7/26/18.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(!root->left){
            return 1+minDepth(root->right);
        }
        if(!root->right){
            return 1+minDepth(root->left);
        }
        int l = minDepth(root->left);

        int r = minDepth(root->right);

        return l < r ? l + 1: r + 1;
    }
};

