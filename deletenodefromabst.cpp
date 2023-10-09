#include<bits/stdc++.h>
using namespace std;
class TreeNode{
	public:
		int val;
		TreeNode *left,*right;
		TreeNode(int data){
			this->val=data;
			left=right=NULL;
		}
};
TreeNode *lastrightnode(TreeNode *root){
	if(root->right==NULL)return root;
	return lastrightnode(root->right);
}
TreeNode* helper(TreeNode *root){
	if(root->left==NULL){
		return root->right;
	}
	else if(root->right==NULL){
		return root->left;
	}
	TreeNode *rightchild=root->right;
	TreeNode *lastright=lastrightnode(root->left);
	lastright->right=rightchild;
	return root->left;
	
}
TreeNode *deleteNode(TreeNode *root,int key){
	TreeNode *dummy=root;
	if(root==NULL)return root;
	if(root->val==key){
		return helper(root);
	}
	
	while(root!=NULL){
		if(root->val > key){
			if(root->left!=NULL && root->left->val==key){
				root->left=helper(root->left);
				break;
			}
			else
				root=root->left;
		}else{
			if(root->right!=NULL && root->right->val==key){
				root->right=helper(root->right);
				break;
			}
			else
				root=root->right;	
		}
	}
	
	return dummy;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    TreeNode *root=new TreeNode(8);
    root->left=new TreeNode(5);
    root->right=new TreeNode(12);
    root->left->left=new TreeNode(2);
    root->left->left->left=new TreeNode(1);
    root->left->left->right=new TreeNode(3);
    root->left->left->right->right=new TreeNode(4);
    root->left->right=new TreeNode(7);
    root->left->right->left=new TreeNode(6);
    root->left->right->right=new TreeNode(8);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(13);
    TreeNode *ans=deleteNode(root,5);
    cout<<ans->val;
}