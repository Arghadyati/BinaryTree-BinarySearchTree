#include<bits/stdc++.h>
using namespace std;
class TreeNode{
	public:
		int val;
		TreeNode *left, *right;
	TreeNode(int val){
		this->val=val;
		left=right=NULL;
	}
};
TreeNode *kthSmallest(TreeNode *root,int &k){
	if(root==NULL)return root;
	TreeNode *left=kthSmallest(root->left,k);
	if(left!=NULL)return left;
	k--;
	if(k==0)return root;
	return kthSmallest(root->right,k);
	
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(4);
    root->left->left->right=new TreeNode(2);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(8);
    int k=3;
    TreeNode *ans=kthSmallest(root,k);
    cout<<ans->val;
}