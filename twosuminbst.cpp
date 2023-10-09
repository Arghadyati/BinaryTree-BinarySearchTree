#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node *left,*right;
		node(int val){
			this->data=val;
			left=right=NULL;
		}
};
void inorder(node *root,vector<int> &ans){
	if(root==NULL)return;
	inorder(root->left,ans);
	ans.push_back(root->data);
	inorder(root->right,ans);
}
bool twosum(vector<int>&ans,int k){
	for(int i=0;i<ans.size();i++){
		for(int j=i+1;j<ans.size();j++){
			if(ans[i]+ans[j]==k)return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    node *root=new node(5);
    root->left=new node(3);
    root->right=new node(6);
    root->right->right=new node(7);
    root->left->left=new node(2);
    root->left->right=new node(4);
    vector<int>ans;
    inorder(root,ans);
    if(twosum(ans,9)){
    	cout<<"TRUE"<<"\n";
    }
    else{
    	cout<<"NO"<<"\n";
    }
}