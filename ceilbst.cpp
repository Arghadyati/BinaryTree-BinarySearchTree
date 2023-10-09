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
int findCeil(TreeNode *root,int key){
	int ceil=-1;
	while(root){
		if(root->val==key){
			ceil=root->val;
			return ceil;
		}

		else if(root->val>key){
			ceil=root->val;
			root=root->left;
		}
		else if(root->val<key){
			root=root->right;
		}
	}
	return ceil;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    TreeNode *root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(13);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(6);
    root->left->left->left=new TreeNode(2);
    root->left->left->right=new TreeNode(4);
    root->left->right->right=new TreeNode(9);
    root->right->left=new TreeNode(11);
    root->right->right=new TreeNode(14);
    int answer=findCeil(root,8);
    cout<<answer;
   
}