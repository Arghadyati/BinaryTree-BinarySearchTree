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
TreeNode *LowestCommonAncestor(TreeNode *root,TreeNode *p,TreeNode *q){
	if(root==NULL)return root;
	TreeNode *cur=root;
	if(cur->val<p->val && cur->val<q->val){
	return	LowestCommonAncestor(root->right,p,q);
	}
	if(cur->val>p->val && cur->val>q->val){
	 return	LowestCommonAncestor(root->left,p,q);
	}

	return root;
	
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    TreeNode *root=new TreeNode(6);
    root->left=new TreeNode(2);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(3);
    root->left->right->right=new TreeNode(5);
    root->right->left=new TreeNode(7);
    root->right->right=new TreeNode(9);
    TreeNode *p=root->left->right->right;
    TreeNode *q=root->left->left;
    TreeNode *ans=LowestCommonAncestor(root,p,q);
    cout<<ans->val<<"\n";
    
}