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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        return new TreeNode(val);
        TreeNode *cur=root;
        while(root){
            if(root->val <= val){
                if(root->right!=NULL){
                    root=root->right;
                }
                else{
                    root->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(root->left!=NULL){
                    root=root->left;
                }
                else{
                    root->left=new TreeNode(val);
                    break;
                }
            }
        }
        return cur;
    }
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(9);
    TreeNode *ans=insertIntoBST(root,5);
    cout<<ans->val;
}