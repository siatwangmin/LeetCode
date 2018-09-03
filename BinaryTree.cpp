#include<iostream>
#include<stack>

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
private:
	vector<int> res;
	
public:
	vector<int> recPreorderTraversal(TreeNode* root){
		if(!root){
			return res;
		}
		res.push_back(root->val);
		recPreorderTraversal(root->left);
		recPreorderTraversal(root->right);
		return res;
	}


	vector<int> recPostorderTraversal(TreeNode* root){
		if(!root){
			return res;
		}	
		recPostorderTraversal(root->left);
		recPostorderTraversal(root->right);
		res.push_back(root->val);
	}

	vector<int> recInorderTraversal(TreeNode* root){
		if(!root)
			return res;
		recInorderTraversal(root->left);
		res.push_back(root->val);
		recInorderTraversal(root->right);
		return res;	
	}


	vector<int> iterPreorderTraversal(TreeNode* root){
		stack<TreeNode*> sta;
		vetor<int> vec;		
		while(root || !sta.empty()){
			while(root){
				s.push(root);
				vec.push_back(root-val);
				root = root->left;			
			}
			root = s.top();
			s.pop();s
			root = root->right;
		}
		return vec;
	}

	vector<int> iterPostorderTraversal(TreeNode* root){
		stack<TreeNode*> s;
		vecotor<int> vec;
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

	vector<int> iterInorderTraversal(TreeNode* root){
		stack<TreeNode*> s;
		vector<int> vec;
		while(root || !s.empty()){
			while(root){
				s.push(root);
				root = root->left;			
			}		
			root = s.top();
			s.pop();
			vec.push_back(root->val);
			root = root->right;
		}	
	}

	void BubleSort(vector<int>& vec){
		size_t  n = vec.size();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n - 1; j++){
				if(vec[j] > vec[j+1]){
					swap(vec[j], vec[j+1]);				
				}			
			}		
		}
	}

	void BubleSort(vector<int>& vec){
		size_t  n = vec.size();
		for(int i = 0; i < n; i++){
			for(int j = i; j < n - 1; j++){
				if(vec[i] > vec[j+1]){
					swap(vec[j], vec[j+1]);				
				}			
			}		
		}
		return vec;	
	}
	
	


};
