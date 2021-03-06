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
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return l > r ? l + 1: r + 1;
    }
};
