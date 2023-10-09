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
bool validBST(TreeNode *root, int minval, int maxval){
	if(root==NULL)return true;
	if(root->val>=maxval ||root->val<=minval)return false;
	return validBST(root->left,minval,root->val)&& validBST(root->right,root->val,maxval);
}
bool isValidBST(TreeNode *root){

	bool ans=validBST(root,INT_MIN,INT_MAX);
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(1);
    root->right=new TreeNode(7);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(8);
    if(isValidBST(root))cout<<"TRUE";
    else
    	cout<<"FALSE";
    
}