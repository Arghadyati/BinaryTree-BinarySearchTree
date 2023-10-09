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
TreeNode *inorderSuccessor(TreeNode *root,TreeNode *p){
	TreeNode *successor=NULL;
	while(root!=NULL){
		if(p->val>=root->val){
		root=root->right;
		}
		else{
			successor=root;
			root=root->left;
		}
	}
	return successor;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->left->left->left=new TreeNode(1);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    root->right->right->left=new TreeNode(8);
    root->right->right->right=new TreeNode(10);
    TreeNode *a=root->right->right->left;
    TreeNode *ans=inorderSuccessor(root,a);
    cout<<ans->val;
}