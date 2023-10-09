#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node*left,*right;
node(int val){
	this->data=val;
	left=right=NULL;
}	
};
node *searchBST(node *root,int d){
	while(root!=NULL&&root->data!=d){
		if(root->data>d){
			root=root->left;
		}
		else if(root->data<d){
			root=root->right;
		}
	}
	return root;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    node *root=new node(8);
    root->left=new node(5);
    root->right=new node(12);
    root->left->left=new node(4);
    root->left->right=new node(7);
    root->left->right->left=new node(6);
    root->right->left=new node(10);
    root->right->right=new node(14);
    root->right->right->left=new node(13);
    int d=10;
    node *ans=searchBST(root,d);
    cout<<ans->data;
    
}