	#include<bits/stdc++.h>
	using namespace std;
	class TreeNode{
	public:
	    int data;
	    TreeNode *left;
	    TreeNode *right;
	    TreeNode(int val){
	    	this->data=val;
	    	right=left=NULL;
	    }
	};
	void levelorder(TreeNode *root,vector<vector<int>>&ans){
     
     queue<TreeNode*>q;

     q.push(root);

     while(!q.empty()){
     int size=q.size();
     vector<int>level;
     for(int i=0;i<size;i++){
      TreeNode* node=q.front();
      q.pop();
      if(node->left!=NULL)q.push(node->left);
      if(node->right!=NULL)q.push(node->right);
      level.push_back(node->data);

     }

     ans.push_back(level);
     }

	

	}

	
	int main(){
		ios::sync_with_stdio(0);
	    cin.tie(0);
	    TreeNode *root=new TreeNode(1);
	    root->left=new TreeNode(2);
	    root->right=new TreeNode(3);
	    root->left->left=new TreeNode(4);
	    root->left->right=new TreeNode(5);
	    root->right->left=new TreeNode(6);
	    root->right->right=new TreeNode(7);
	    vector<vector<int>>ans;
	    levelorder(root,ans);
	    for(auto vctr:ans){
	    	for(auto it:vctr){
	    		cout<<it<<" ";
	    	}

	    }
	}