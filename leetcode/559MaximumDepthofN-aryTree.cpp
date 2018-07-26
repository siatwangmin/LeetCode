//
// Created by wangmin on 7/26/18.
//


// Definition for a Node.


#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root){
            return 0;
        }
        int depth = 0;

        for(vector<Node*>::iterator iter = root->children.begin(); iter != root->children.end(); ++iter){
            int r = maxDepth(*iter);
            if(r > depth){
                depth = r;
            }
        }
        return depth + 1;
    }
};